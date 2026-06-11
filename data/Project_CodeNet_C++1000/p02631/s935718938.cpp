#include <bits/stdc++.h>
#define in(x) freopen(x, "r", stdin)
#define out(x) freopen(x, "w", stdout)
using namespace std;

const int N = (int)(2e5 + 500);

int n;
int a[N], res[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                
    #ifndef _LOCAL          
    #endif // _LOCAL

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int all_xor = 0;
    for (int i = 0; i < n - 1; ++i)
        all_xor ^= a[i];

    res[n - 1] = all_xor;

    for (int i = n - 2; i >= 0; --i)
        res[i] = a[i] ^ a[i + 1] ^ res[i + 1];

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";

    return 0;
}