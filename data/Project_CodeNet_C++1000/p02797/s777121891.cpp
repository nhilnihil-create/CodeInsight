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
    int n, k;
    ll s;
    cin >> n >> k >> s;
    rep(i,k) cout << s << " ";
    if(s != 1000000000){
        rep(i,n-k) cout << s+1 << " ";
    }
    else{
        rep(i,n-k) cout << 1 << " ";
    }
    cout << endl;
    return 0;
}