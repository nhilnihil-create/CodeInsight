#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;
    bool approved = true;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        if(!(a & 1) && a % 3 != 0 && a % 5 != 0) {
            approved = false;
            break;
        }
    }

    cout << (approved ? "APPROVED" : "DENIED") << "\n";

    return 0;
}