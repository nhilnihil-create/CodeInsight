#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9, mod = 1e9+7;
#define endl     '\n'

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int cnt = 0;
    while (a >= b) b *= 2, cnt++;
    while (b >= c) c *= 2, cnt++;
    cout << (cnt <= k ? "Yes" : "No");
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
