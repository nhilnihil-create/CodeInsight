#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (size_t i = 0; i < n; i++) cin >> d[i];

    long long ans = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i+1; j < n; j++) {
            ans += d[i] * d[j];
        }
    }

    cout << ans << endl;
    return 0;
}
