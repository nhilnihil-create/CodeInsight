
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i = 0; i< N; i++)

int main() {
    int n, m; cin >> n >> m;
    vector<int> h(n+1);
    vector<int> to[n+1];
    rep(i,n) cin >> h[i+1];
    int ans = 0;
    rep(i,m) {
        int a, b;
        cin >> a >> b;

        to[a].push_back(h[b]);
        to[b].push_back(h[a]);
    }

    rep(i,n) {
        if(to[i+1].size() == 0) {
            ans++;
            continue;
        }
        vector<int>::iterator iter = max_element(to[i+1].begin(), to[i+1].end());
        if(h[i+1] > *iter) ans++;
    }
    cout << ans << endl;
}
