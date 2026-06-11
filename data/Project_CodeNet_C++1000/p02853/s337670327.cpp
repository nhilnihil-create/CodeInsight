#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int x, y;
    cin >> x >> y;
    ll ans = 0;
    if(x == 3) {
        if(y == 3) {
            ans += 200000;
        }
        else if(y == 2) {
            ans += 300000;
        }
        else if(y == 1) {
            ans += 400000;
        }
        else ans += 100000;
    }
    else if(x == 2) {
        if(y == 3) {
            ans += 300000;
        }
        else if(y == 2) {
            ans += 400000;
        }
        else if(y == 1) {
            ans += 500000;
        }
        else ans += 200000;
    }
    else if(x == 1) {
        if(y == 3) {
            ans += 400000;
        }
        else if(y == 2) {
            ans += 500000;
        }
        else if(y == 1) {
            ans += 1000000;
        }
        else ans += 300000;
    }
    else {
        if(y == 3) {
            ans += 100000;
        }
        else if(y == 2) {
            ans += 200000;
        }
        else if(y == 1) {
            ans += 300000;
        }
        else ans += 0;
    }
    cout << ans << endl;
    return 0;
}