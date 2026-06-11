#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
#define ll long long
#define INF (int)(1e9+5)
#define MOD (int)(1e9 + 7) 
#define pi 3.14159265

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> red(a), green(b), col(c);
    for(int &i : red) cin >> i;
    for(int &i : green) cin >> i;
    for(int &i : col) cin >> i;
    sort(red.begin(), red.end(), greater<int>());
    sort(green.begin(), green.end(), greater<int>());
    for(int i = 0; i < x; ++i) col.push_back(red[i]);
    for(int i = 0; i < y; ++i) col.push_back(green[i]);
    sort(col.begin(), col.end(), greater<int>());
    ll ans = 0;
    for(int i = 0; i < x+y; ++i) ans += col[i];
    cout << ans << '\n';
    return 0;
}

