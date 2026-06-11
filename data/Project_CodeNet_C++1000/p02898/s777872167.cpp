
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, t, res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t >= k)
            ++res;
    }
    cout << res << endl;

    return 0;
}

