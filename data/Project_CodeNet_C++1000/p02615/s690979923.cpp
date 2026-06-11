#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.rbegin(), v.rend());
    int id = 0;
    long long ans = 0;
    for (int i(0); i < n - 1; ++i) {
        ans += v[id];
        if (i & 1 ^ 1) {
            id++;
        }
    }
    cout << ans << endl;
}