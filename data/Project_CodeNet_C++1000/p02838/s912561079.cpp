#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

//modの世界の2のn乗を返す
ll safe2pow(int n){
    ll ans = 1;
    rep(i,n){
        ans = ans * 2 % mod;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<ll> As(n);
    ll ans = 0;
    rep(i,n) cin >> As.at(i);
    rep(i,60){
        int pi = 0 , qi = 0;
        rep(j,n){
            bitset<60> bs(As.at(j));
            if(bs.test(i)){
                qi++;
            } else {
                pi++;
            }
        }
        ans = (ans + pi * safe2pow(i) % mod * qi) % mod;
    }
    cout << ans << endl;
    return 0;
}
