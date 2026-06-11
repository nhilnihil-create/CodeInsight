#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n-1];
    for (int i=0; i<n-1; i++) cin >> b[i];
    a[0] = b[0];
    for (int i=1; i<n-1; i++) {
        a[i] = min(b[i-1], b[i]);
    }
    a[n-1] = b[n-2];
    int ans = 0;
    for (int i=0; i<n; i++) ans += a[i];
    cout << ans << '\n';
    
    return 0;
}