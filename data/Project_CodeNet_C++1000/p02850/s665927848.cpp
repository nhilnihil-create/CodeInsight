//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(make_pair(i, b));
        G[b].push_back(make_pair(i, a));
    }

    queue<int> Q;
    Q.push(0);
    vi kir(n-1, -1);
    int i_ = -1;
    while(!Q.empty()) {
        int now = Q.front();
        Q.pop();
        int x = 0;
        for(auto next:G[now]) {
            if(kir[next.first] != -1) i_ = next.first;
        }
        for(auto next:G[now]) {
            if(i_ != -1 && kir[i_] == x) {
                ++x;
            }
            if(kir[next.first] != -1) continue;
            kir[next.first] = x;
            ++x;
            Q.push(next.second);
        }
    }
    cout << *max_element(kir.begin(), kir.end())+1 << '\n';
    rep(i, n-1) {
        cout << kir[i]+1 << '\n';
    }
}