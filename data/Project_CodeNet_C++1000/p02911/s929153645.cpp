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
    ll n, k, q, a;
    cin >> n >> k >> q;
    vector<ll> r(n, k-q);
    rep1(i, q){
        cin >> a;
        r[a-1]++;
    }
    rep1(i,n){
        if (r[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}