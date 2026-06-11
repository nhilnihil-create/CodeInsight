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
    cin >> n >> k;
    int c = (n-1)*(n-2)/2;
    if(k > c){
        cout << -1 << endl;
        return 0;
    }
    vector<P> ans;
    for(int i = 2; i <= n; ++i) ans.emplace_back(1, i);
    for(int i = 2; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            if(c <= k) break;
            ans.emplace_back(i, j);
            --c;
        }
        if(c <= k) break;
    }
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first << " " << p.second << endl;
    return 0;
}
