#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1, 0), ans;
    rep(i,n) cin >> a[i+1];
    for(int i = n; i > 0; --i){
        int sum = 0;
        for(int j = i+i; j <= n; j += i){
            sum += b[j];
        }
        if(sum%2 == a[i]) b[i] = 0;
        else{
            b[i] = 1;
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
