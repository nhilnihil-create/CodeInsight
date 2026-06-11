#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> a;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < (int)a.size(); i++) {
        cout << a[i].second << ' ';
    }
    return 0;
}