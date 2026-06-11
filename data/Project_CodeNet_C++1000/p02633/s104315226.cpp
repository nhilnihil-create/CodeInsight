#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int x, i = 0; cin >> x;
    while(true)
    {
        i++;
        if (x * i % 360 == 0) break;
    }
    cout << i << endl;
    return 0;
}