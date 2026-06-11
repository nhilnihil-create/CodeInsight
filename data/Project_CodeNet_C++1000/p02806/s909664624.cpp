#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<pair<string, int> > v(n);
    long long ans = 0;
    string x;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (f) {
            ans += v[i].second;
        }
        if (v[i].first == x) f = 1;
        
    }
    cout << ans << endl;
}