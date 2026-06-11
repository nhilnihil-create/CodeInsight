#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int x, y;
    int maxsum = -m, minsum = m, maxdiff = -m, mindiff = m;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        maxsum = max(maxsum, x + y);
        maxdiff = max(maxdiff, x - y);
        minsum = min(minsum, x + y);
        mindiff = min(mindiff, x - y);
    }
    if(maxsum - minsum > maxdiff - mindiff)
        cout << maxsum - minsum;
    else
        cout << maxdiff - mindiff;
}