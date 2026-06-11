
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    --n;
    res = 1LL * (1 + n) * n / 2;
    cout << res << endl;

    return 0;
}

