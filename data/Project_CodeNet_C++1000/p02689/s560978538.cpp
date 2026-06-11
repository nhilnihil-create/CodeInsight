#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 300006;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<bool> bad(n);
    for(int& x : a) cin >> x;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[y] <= a[x]) bad[y] = true;
        if (a[x] <= a[y]) bad[x] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (!bad[i]);
    cout << ans << '\n';
    return 0; 
}
 