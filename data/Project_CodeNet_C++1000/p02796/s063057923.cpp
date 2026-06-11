#include <bits/stdc++.h>
using namespace std;
int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n, ans = 1, ls;
        cin >> n;
        vector<pair<int, int> > v(n);
        for(int i = 0, x, l; i < n; ++i) {
                cin >> x >> l;
                v[i] = {x - l, x + l};
        }
        sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
                if(a.second != b.second) return a.second < b.second;
                return a.first < b.first;
        });
        ls = v[0].second;
        for(int i = 1; i < n; ++i)
                if(ls <= v[i].first) ++ans, ls = v[i].second;
        cout << ans;
        return 0;
}
