#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (2147483647)
#define MOD (int)(1e9 + 7) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    ans += n * (n - 1) / 2;
    ans += m * (m - 1) / 2;
    cout << ans << '\n';
    return 0;
}