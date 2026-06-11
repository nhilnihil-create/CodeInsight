#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    int ans = 0;
    if(x == 3) ans += 100000;
    if(x == 2) ans += 200000;
    if(x == 1) ans += 300000;
    if(y == 3) ans += 100000;
    if(y == 2) ans += 200000;
    if(y == 1) ans += 300000;
    if(x == 1 && y == 1) ans += 400000;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
