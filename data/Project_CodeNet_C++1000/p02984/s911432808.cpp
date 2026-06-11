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
    vector<ll> a(n, 0), b(n);
    rep(i,n){
        cin >> b[i];
        if(i%2 == 0) a[0] += b[i];
        else a[0] -= b[i];
    }
    cout << a[0];
    for(int i = 1; i < n; ++i){
        a[i] = 2*b[i-1] - a[i-1];
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}