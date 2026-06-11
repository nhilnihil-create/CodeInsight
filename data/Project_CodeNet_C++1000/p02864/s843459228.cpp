#include <bits/stdc++.h>
using namespace std;

long h[333], d[333][333];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int x = 0; x < n; x++)
        fill(d[x], d[x] + k + 1, 1e18);
    for(int i = 0; i < n; i++) {
        for(int j = k + 1; j--;) {
            d[i][j] = 1e18;
            for(int x = 0; x <= n; x++) {
                if(i)
                    d[i][j] = min(d[i][j], d[x][j] + max(h[i] - h[x], 0l));
                else
                    d[i][j] = h[i];
                if(x != i)
                    d[x][j] = j ? d[x][j - 1] : 1e18;
            }
        }
    }
    for(int i = 0; i <= n; i++)
        d[0][k] = min(d[0][k], d[i][k]);
    cout << d[0][k] << endl;
    return 0;
}
