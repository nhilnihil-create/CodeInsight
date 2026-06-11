#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for (int i=0; i<n; i++) cin >> h[i];
    int d[n+1] = {0};
    d[0] = 0;
    for (int i=1; i<=n; i++) {
        if (h[i] <= h[i-1]) d[i] = d[i-1] + 1;
        else d[i] = 0;
    }
    int ans = *max_element(d, d+n);
    cout << ans << '\n';
    
    return 0;
}