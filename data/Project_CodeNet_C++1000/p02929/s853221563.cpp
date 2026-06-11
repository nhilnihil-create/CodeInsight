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
#include<cstdio>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)2e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

#define MAX 100010
ll fac[MAX];
ll finv[MAX];
ll inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    repr(i,2,MAX){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}



int main(){
	int N; cin >> N;
	string S; cin >> S;
	rep(i,2*N){
		if(i % 2 == 0){
			if(S[i] == 'W') S[i] = 'B';
			else S[i] = 'W';
		}
	}
	ll cnt = 0;
	ll cnt2 = 0;
	ll now = 0;
	ll ans = 1;
	rep(i,2*N){
		if(S[i] == 'W'){
			cnt++;
			now++;
		}
		if(S[i] == 'B'){
			cnt2++;
			ans *= now;
			ans %= MOD;
			now--;
		}
	}
	if(cnt != cnt2){
		cout << 0 << endl;
		return 0;
	}
	COMinit();
	ans *= fac[N];
	ans %= MOD;
	cout << ans << endl;

}
