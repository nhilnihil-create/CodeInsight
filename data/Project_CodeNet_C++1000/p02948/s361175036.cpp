#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> data(n);
    rep(i,n) cin >> data[i].first >> data[i].second;
    sort(all(data));
    vector<ll> a(n); rep(i,n) a[i] = data[i].first;
    
    ll ans = 0;
    ll save = 0;
    priority_queue<ll> pq;
    for(int i = 1; i <= m; i++){
        int k = upper_bound(all(a),i) - a.begin();
        for(int j = save; j < k; j++) pq.push(data[j].second);
        // 候補の追加
        if(!pq.empty()){
            ans += pq.top(); pq.pop();
        }
        // 最大のものを取り出す
        save = k;
    }
    cout << ans << endl;
}