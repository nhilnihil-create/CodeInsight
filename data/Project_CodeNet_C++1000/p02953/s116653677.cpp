#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (size_t i = 0; i < n; i++) cin >> h[i];

    bool ok = false;
    for (int i = n-2; i >= 0; i--) {
        if (h[i] > h[i+1]) {
            h[i]--;
            if (h[i] > h[i+1]) break;
        }

        if (i == 0) ok = true;
    }

    if (ok || n == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
