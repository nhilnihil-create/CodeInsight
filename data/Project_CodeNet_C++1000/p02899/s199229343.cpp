#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    pair<int, int> p;
    rep(i, n) {
        cin >> p.first;
        p.second = i + 1;
        v[i] = p;
    }
    sort(v.begin(), v.end());
    rep(i, n) { cout << v[i].second << " "; }
    cout << endl;
    return 0;
}