#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef _LOCAL_DEBUG
#include "templates/debug.h"
#else
#define debug(...) 
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d = 0, k;
    cin >> a >> b >> c >> k;
    while (b <= a)
        b *= 2, d++;
    while (c <= b)
        c *= 2, d++;
    cout << (d <= k ? "Yes" : "No") << endl;
    return 0;
}
