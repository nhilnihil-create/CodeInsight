#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll h, w, k, ans = 0;
    cin >> h >> w >> k;
    vector<vector<char> > c(w, vector<char>(h));
    rep(y, h){
        rep(x, w){
            cin >> c.at(x).at(y);
        }
    }
    rep(bit, (1<<(h+w))){
        bitset<12> tmp(bit);
        vector<vector<char> > m = c;
        rep(i, h){
            if(tmp.test(i)) {
                rep(x, w){
                    m.at(x).at(i) = '.';
                }
            }
        }
        rep2(i, h, h+w){
            if(tmp.test(i)) {
                rep(y, h){
                    m.at(i-h).at(y) = '.';
                }
            }
        }
        int count = 0;
        rep(y, h){
            rep(x, w){
                if(m.at(x).at(y) == '#'){
                    count++;
                }
            }
        }
        if(count == k){
            ans++;
        }
    }
    cout << ans << endl;
}