#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    map<ll,ll> S;
    ll a_max = 0;
    bool t = true;
    rep(i,N) {
        ll a;
        cin >> a;
        a_max = max(a,a_max);
        S[a]++;
        if (i==0 && a!=0) {
          t = false;
        }
    }
    ll ans = 1;
    ll p = 1;

    if (S[0]!=1) {
        cout << 0 << endl;
    }
    else if (!t) {
      cout << 0 << endl;
    }
    else {
        for (ll i = 1; i<=a_max; i++) {
            if (S[i]==0) {
                ans = 0;
                break;
            }
            else {
                ll tmp=1;
                rep(j,S[i]) {
                    tmp*=p;
                    tmp%=998244353;
                }
                ans *= tmp;
                ans %= 998244353;
                p = S[i];   
            }
        }
        cout << ans << endl;
    }
    
}
