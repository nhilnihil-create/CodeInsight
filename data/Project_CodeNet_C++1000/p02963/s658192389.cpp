#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll s;
    cin >> s;
    ll x1 = 0, y1 = 0, x2 = INF, y2 = 1;
    ll x3 = (INF - s%INF) % INF;
    ll y3 = (s + x3) / INF;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    return 0;
}