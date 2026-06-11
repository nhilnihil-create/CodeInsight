#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1000000007;
const int INF = 1001001001;


int main(){
    int n, m;
    cin >> n >> m;
    vector<P> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int index = 0;
    auto comp = [](P a, P b) {
        return a.second<b.second;
    };
    ll ans = 0;
    priority_queue<P, vector<P>, decltype(comp)> q {comp};
    
    for (int i=1; i<=m; i++) {
        
        while (p[index].first<=i && index<n) {
            q.push(p[index]);
            index++;
        }
        
        if (!q.empty()) {
            P now = q.top();
            q.pop();
            ans += now.second;
        }
    }
    
    
    
    cout << ans << endl;
    return 0;
}
