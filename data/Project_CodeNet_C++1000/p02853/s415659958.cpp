#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int x){
    if(x == 1) return 300000;
    if(x == 2) return 200000;
    if(x == 3) return 100000;
    return 0;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    int ans = f(X) + f(Y);
    if(X+Y == 2) ans += 400000;
    cout << ans << "\n";
    return 0;
}