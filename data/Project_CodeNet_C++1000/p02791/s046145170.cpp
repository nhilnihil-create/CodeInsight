#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (size_t i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    int min = 3000000;
    for (size_t i = 0; i < n; i++) {
        if (p[i] < min) min = p[i];
        if (min == p[i]) ++ans;
    }

    cout << ans << endl;
    return 0;
}
