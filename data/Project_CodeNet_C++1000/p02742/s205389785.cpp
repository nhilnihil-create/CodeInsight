#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    ll h, m;
    cin >> h >> m;
    if(h == 1 || m == 1) {
        cout << 1 << endl;
        return 0;
    }
    cout << (h * m + 1) / 2 << endl;
    return 0;
}