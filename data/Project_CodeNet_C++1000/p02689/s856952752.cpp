#include <iostream>
using namespace std;
int main()
{
    int n, m, a, b, ans = 0;
    int h[100001] = {}, ab[100001] = {};
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if(ab[a] < h[b]) {
            ab[a] = h[b];
        }
        if(ab[b] < h[a]) {
            ab[b] = h[a];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(h[i] > ab[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}