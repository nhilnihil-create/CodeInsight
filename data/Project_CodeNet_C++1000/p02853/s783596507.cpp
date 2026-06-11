#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
int f(int x) {
    if (x == 1) return 300000;
    else if (x == 2) return 200000;
    else if (x == 3) return 100000;
    return 0;
}
/* main */
int main(){
    int x, y;
    cin >> x >> y;
    int ans = (x == 1 && y == 1) ? 400000 : 0;
    ans += f(x) + f(y);
    cout << ans << '\n';
}