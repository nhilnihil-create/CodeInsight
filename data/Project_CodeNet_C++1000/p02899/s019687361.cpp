#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i).first;
        a.at(i).second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a.at(i).second;
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}