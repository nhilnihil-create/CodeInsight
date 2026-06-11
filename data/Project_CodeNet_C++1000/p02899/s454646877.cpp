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
    ll n, a;
    cin >> n;
    vector<P> p;
    rep1(i, n){
        cin >> a;
        P pnow;
        pnow.first = a;
        pnow.second = i;
        p.push_back(pnow);
    }
    sort(p.begin(), p.end());
    rep1(i,n){
        if (i==n-1) cout << p[i].second + 1 << endl;
        else cout << p[i].second + 1 << " ";
    }
}