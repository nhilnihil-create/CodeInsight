#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    int x;
    cin >> x;
    int rank;
    if(400 <= x && x <= 599) rank = 8;
    if(600 <= x && x <= 799) rank = 7;
    if(800 <= x && x <= 999) rank = 6;
    if(1000 <= x && x <= 1199) rank = 5;
    if(1200 <= x && x <= 1399) rank = 4;
    if(1400 <= x && x <= 1599) rank = 3;
    if(1600 <= x && x <= 1799) rank = 2;
    if(1800 <= x && x <= 1999) rank = 1;
    cout << rank << endl;
    return 0;
}