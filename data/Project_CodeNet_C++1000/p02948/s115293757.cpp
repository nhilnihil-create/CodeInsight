#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
//const int MOD = 1e9 + 7;
using intpair = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int n, m;
    cin >> n >> m;
    vector<intpair> a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(ALL(a));
    
    auto it = a.begin();
    priority_queue<int> q;
    ll ans = 0;
    reps(i,1,m){
        while(it != a.end()){
            if(it->first != i) break;
            q.push(it->second);
            it++;
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    
    cout << ans << endl;
}