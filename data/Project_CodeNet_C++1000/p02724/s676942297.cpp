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
    int x;
    cin >> x;
    ll ans = 0;
    ans += (x / 500) * 1000;
    x -= (x / 500) * 500;
    ans += (x / 5) * 5;
    cout << ans << '\n';
    return 0;
}

