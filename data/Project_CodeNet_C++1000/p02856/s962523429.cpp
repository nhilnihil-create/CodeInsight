#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


int main(){
    int m;
    cin >> m;

    ll d = 0;
    ll s = 0;
    rep(i, m){
        ll x, c;
        cin >> x >> c;
        d += c;
        s += x*c;
    }
    
    ll ans = (d-1) + (s-1)/9;
    cout << ans << endl;
}