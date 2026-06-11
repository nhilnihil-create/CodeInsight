#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

int main() {
    int n; cin >> n;
    int m = 1<<n;
    multiset<int> ss;
    rep(i, m) {
        int in; cin >> in;
        ss.insert(-in);
    }
    vector<int> v { *ss.begin() };
    ss.erase(ss.begin());
    rep(i, n) {
        for (int j=0; j<(1<<i); ++j) {
            auto it = ss.upper_bound(v[j]); // 引数より大きい最初の要素のイテレータ
            if (it==ss.end()) {
                cout << "No" << endl;
                return 0;
            }
            v.push_back(*it);
            ss.erase(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}