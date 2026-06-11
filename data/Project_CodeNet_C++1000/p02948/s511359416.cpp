#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> a;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    priority_queue<int> que;
    int idx = 0;
    for(int d = 1; d <= m; d++){
        while(a[idx].first == d){
            que.push(a[idx].second);
            idx++;
        }
        if(!que.empty()){
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}