#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
int main() {
    int tHp, tAt, aHp, aAt;
    cin >> tHp >> tAt >> aHp >> aAt;

    while(tHp>0&&aHp>0) {
        aHp -= tAt;
        tHp -= aAt;
    }
    if (aHp<=0) cout << "Yes" << endl;
    else cout << "No" << endl;
}