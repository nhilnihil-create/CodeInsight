#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        ans[x-1]++;
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
}
