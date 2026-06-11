#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s, r, l;
    cin >> s;
    ll q;
    cin >> q;
    ll t, f, count=0;
    char c;
    rep1(i, q){
        cin >> t;
        if (t == 1){
            swap(r, l);
            count++;
        } else{
            cin >> f >> c;
            if (f == 1) l += c;
            else r += c;
        }
    }
    if (count%2 == 1) reverse(s.begin(), s.end());
    reverse(l.begin(), l.end());
    string ans = l + s + r; 
    cout << ans << endl;
    //printf("%.12f", ans);
}