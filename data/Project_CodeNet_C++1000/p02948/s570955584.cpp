#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(100001);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    ll ans = 0;
    priority_queue<ll> pq;
    for(int i = 1; i <= m; ++i){
        for(auto e : v[i]) pq.push(e);
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
