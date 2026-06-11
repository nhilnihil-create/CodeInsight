#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int X, Y;
    cin >> X >> Y;
    bool bl = (X * 2 <= Y && X * 4 >= Y && Y % 2 == 0);
    puts(bl ? "Yes" : "No");
    return 0;
    // ll, 0, -, 1i, for s&g
}