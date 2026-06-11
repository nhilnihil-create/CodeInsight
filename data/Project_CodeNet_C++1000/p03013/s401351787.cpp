#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool broken[100001];
#define mod 1000000007
int main () {
    int n, m;
    cin >> n >> m;
    ll x[n + 1];
    memset(x, 0, sizeof(x));
    memset(broken, false, sizeof(broken));
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }
    x[1] = 1;
    x[2] = 2;
    if (broken[1]) {
        x[2] = 1;
    }
    for (int i = 3; i <= n; i++) {
        if ((broken[i - 1]) && (broken[i - 2])) {
            x[i] = 0;
        }
        else if (broken[i - 1]) {
            x[i] = x[i - 2];
        }
        else if (broken[i - 2]) {
            x[i] = x[i - 1];
        }
        else {
            x[i] = (x[i - 1] + x[i - 2]) % mod;
        }
    }
    cout << x[n] << endl;
    return 0;
}