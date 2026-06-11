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
using namespace std;
 
#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
 
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
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    int sum = 0;
    rep(i,N) sum += a[i];
    set<ll> div = divisor(sum);
    int ans = 0;
    for(int u : div){
        vector<int> b = a;
        rep(i,N) b[i] %= u;
        sort(b.begin(),b.end());
        vector<int> sum2(N+1);
        rep(i,N) sum2[i+1] = sum2[i]+u-b[i];
        int sum = 0;
        rep(i,N){
            sum += b[i];
            if(sum == sum2[N]-sum2[i+1] && sum <= K){
                ans = max(ans,u);
                break;
            }
        }
    }
    cout << ans << endl;
}
