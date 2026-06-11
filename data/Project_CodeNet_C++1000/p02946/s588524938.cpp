
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> x;
    int l = x - k + 1;
    int r = x + k - 1;
    for (int i = l; i <= r; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

