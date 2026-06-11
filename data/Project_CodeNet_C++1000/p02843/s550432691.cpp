#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    int cnt = x / 100;
    int under2 = x % 100;
    if(under2 == 0) {
        cout << 1 << endl;
        return 0;
    }
    if(under2 > 5 * cnt)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}