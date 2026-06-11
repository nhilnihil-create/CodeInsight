#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n+1); for (int i = 0; i < n; i++) cin >> a[i+1];

    vector<int> cyc; cyc.push_back(1);
    vector<int> lastind(n+1, -1);
    lastind[1] = 0;
    
    int x = 1;
    while (true) {
        x = a[x];
        cyc.push_back(x);
        if (cyc.size()-1 == k) {
            cout << cyc.back() << endl;
            return 0;
        }
        if (lastind[x] != -1) {
            vector<int> path(cyc.begin()+lastind[x]+1, cyc.end());
            k -= lastind[x];
            int ind = k%path.size() - 1;
            if (ind < 0) ind = path.size()-1;
            cout << path[ind] << endl;
            return 0;
        }
        lastind[x] = cyc.size()-1;
    }

    return 0;
}