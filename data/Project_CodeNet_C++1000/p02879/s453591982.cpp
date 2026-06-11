/**
 *    author:  FromDihPout
 *    created: 2020-08-08
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    if (a <= 9 && b <= 9) {
        cout << a * b << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}