#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k>0){
        if (a>=b) b *= 2;
        else if (b>=c) c *= 2;
        k--;
    }
    if (a<b & b<c) cout << "Yes" << endl;
    else cout << "No" << endl;
}