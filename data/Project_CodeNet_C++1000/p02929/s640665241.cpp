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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

#define MAX 200000
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
    COMinit();
    int N; cin >> N;
    string S; cin >> S;
    int cntl = 0;
    int cntr = 0;
    ll ans = 1;
    rep(i,2*N){
        if((cntl-cntr) % 2 != 0){
            if(S[i] == 'W') cntl++;
            else{
                ans *= (cntl-cntr);
                ans %= MOD;
                cntr++;
            }
        }
        else{
            if(S[i] == 'B') cntl++;
            else{
                ans *= (cntl-cntr);
                ans %= MOD;
                cntr++;
            }
        }
        if(cntl < cntr){
            cout << 0 << endl;
            return 0;
        }
    }
    ans *= fac[N];
    ans %= MOD;
    if(cntl != cntr) cout << 0 << endl;
    else cout << ans << endl;
}