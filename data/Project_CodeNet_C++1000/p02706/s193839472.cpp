#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<int(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll total = 0;
    rep(i, m) {
        int ai;
        cin >> ai;
        total += ai;
    }
    
    if (total > n) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << n - total << endl;
    return 0;
}
