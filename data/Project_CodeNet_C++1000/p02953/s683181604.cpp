
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p, cur;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        --cur;
        if (cur < p) {
            ++cur;
            if (cur < p) {
                cout << "No" << endl;
                exit(0);
            }
        }
        p = cur;
    }
    cout << "Yes" << endl;

    return 0;
}

