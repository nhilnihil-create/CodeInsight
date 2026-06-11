#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = 1e9 + 7;
int n, m;

void solve() {
    int x, t;
    cin >> n >> x >> t;
    if (n % x == 0) cout << t * (n / x);
    else cout << t * ((n / x) + 1);

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
