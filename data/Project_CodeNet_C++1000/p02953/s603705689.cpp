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
    vector<ll> h(n, 0);
    rep1(i, n) cin >> h[i];
    bool judge = true;
    rep1(i, n-1){
        if (h[i]>h[i+1]) judge = false;
        else{
            if (h[i]!=h[i+1]) h[i+1]--;
        }
    }
    if (judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}