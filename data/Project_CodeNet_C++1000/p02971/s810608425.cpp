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
    ll n;
    cin >> n;
    vector<ll> a(n, 0), b(n, 0);
    rep1(i, n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    rep1(i, n){
        if (a[i] == b[0]) cout << b[1] << endl;
        else cout << b[0] << endl;
    }
    
}