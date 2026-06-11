//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > gg(n);
    rep(i, n) {
        int a,b;
        cin >> a >> b;
        gg[i] = make_pair(a, b);
    }

    sort(gg.begin(), gg.end());
    int j=0;
    priority_queue<int> pq;
    int ans = 0;
    rep(i, m) {
        int i_ = i+1;
        
        while(gg[j].first <= i_) {
            pq.push(gg[j].second);
            ++j;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;

}