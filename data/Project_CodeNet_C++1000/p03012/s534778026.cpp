#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> ws(n);
    cin >> ws[0];
    for (size_t i = 1; i < n; i++) {
        cin >> ws[i];
        ws[i] += ws[i-1];
    }

    int ans = 100000000;
    for (size_t i = 0; i < n-1; i++) {
        ans = min(ans, abs(ws[n-1] - 2 * ws[i]));
    }

    cout << ans << endl;
    return 0;
}
