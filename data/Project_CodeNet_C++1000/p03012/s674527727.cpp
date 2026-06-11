#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    int ans1 = 0, ans2 = 0, ans = 1000;
    for (int i = 0; i < vec.size(); ++i) {
        ans1 += vec[i];
        for (int j = i + 1; j < vec.size(); ++j) {
            ans2 += vec[j];
        }
        if (ans >= abs(ans1 - ans2)) {
            ans = abs(ans1 - ans2);
        }
        ans2 = 0;
    }

    cout << ans << endl;
}