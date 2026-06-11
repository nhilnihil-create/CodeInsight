#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, pimp, comp;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    pimp = a.size();
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    comp = a.size();
    if (pimp == comp) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
