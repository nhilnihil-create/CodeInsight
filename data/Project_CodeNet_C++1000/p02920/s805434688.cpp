#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    multiset<int> s;
    rep(i, (1<<N)) {
        int si; cin >> si;
        s.insert(si);
    }
    
    multiset<int> s2;
    s2.insert(*--s.end());
    s.erase(--s.end());
    
    rep(i, N) {
        for (auto it=s2.begin(); it!=s2.end(); it++) {
            auto it2 = s.lower_bound(*it);
            if (it2==s.begin()) {
                cout << "No" << endl;
                exit(0);
            }
            s2.insert(*--it2);
            s.erase(it2);
        }
    }
    
    cout << "Yes" << endl;
}