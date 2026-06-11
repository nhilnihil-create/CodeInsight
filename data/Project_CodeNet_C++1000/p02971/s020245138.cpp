#include <bits/stdc++.h>
using namespace std;

int n, x, sol[200005];
vector<pair<int, int>> v;

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    sol[v[n - 1].second] = v[n - 2].first;
    for(int i = n - 2; i >= 0; i--) {
        sol[v[i].second] = v[n - 1].first;
    }
    for(int i = 1; i <= n; i++) {
        cout << sol[i] << '\n';
    }
    return 0;
}