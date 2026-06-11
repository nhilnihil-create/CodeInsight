#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    for(int i = n-2; i >= 0; --i){
        if(h[i] > h[i+1]+1){
            cout << "No" << endl;
            return 0;
        }
        chmin(h[i], h[i+1]);
    }
    cout << "Yes" << endl;
    return 0;
}