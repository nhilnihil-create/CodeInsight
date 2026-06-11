/**
 *    author:  FromDihPout
 *    created: 2020-08-13
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<bool> seen(4);
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        seen[x] = true;
    }
    for (int i = 1; i <= 3; i++) {
        if (!seen[i]) {
            cout << i;
        }
    }
}