#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    vl snuke(N, 0);
    rep(i, K){
        ll d;
        cin >> d;
        rep(j, d){
            ll a;
            cin >> a;
            a--;
            snuke[a]++;
        }
    }
    rep(i, N){
        if(snuke[i] == 0) ans++;
    }
    cout << ans;
}