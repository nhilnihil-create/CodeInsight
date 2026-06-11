
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, t;
double res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10) << fixed;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        res += 1.0L / t;
    }
    cout << 1.0L / res << endl;

    return 0;
}

