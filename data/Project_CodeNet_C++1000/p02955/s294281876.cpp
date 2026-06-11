#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

set<ll> divisor(ll n){
    set<ll> s;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s;
}

int main(){
	int N,K; cin >> N >> K;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	int sum = 0;
	rep(i,N) sum += A[i];
	set<ll> div = divisor(sum);
	int ans = 0;
	for(int u : div){
		vector<int> B = A;
		rep(i,N){
			B[i] %= u;
		}
		sort(B.begin(),B.end());
		vector<int> sum2(N+1),sum3(N+1);
		rep(i,N) sum2[i+1] = sum2[i]+B[i];
		rep(i,N) sum3[i+1] = sum3[i]+u-B[i];
		bool ok = false;
		rep(i,N+1){
			if(sum2[i] == sum3[N]-sum3[i] && sum2[i] <= K) ok = true;
		}
		if(ok) ans = max(ans,u);
	}
	cout << ans << endl;
}

