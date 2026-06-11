
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << setprecision(10) << fixed;
    if (n & 1) {
        double h = (n - 1) / 2;
        cout << double (h + 1) / n << endl;
    } else {
        cout << 0.5 << endl;
    }

    return 0;
}

