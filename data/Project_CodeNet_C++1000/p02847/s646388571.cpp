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
    string s;
    cin >> s;
    ll ans = 0;
    if (s == "MON") ans = 6;
    if (s == "TUE") ans = 5;
    if (s == "WED") ans = 4;
    if (s == "THU") ans = 3;
    if (s == "FRI") ans = 2;
    if (s == "SAT") ans = 1;
    if (s == "SUN") ans = 7;
    cout << ans << endl;
    //printf("%.12f", ans);
}