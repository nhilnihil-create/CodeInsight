/**
 *    author:  FromDihPout
 *    created: 2020-09-11
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    priority_queue<int> price;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        price.push(x);
    }
    
    for (int i = 0; i < m; i++) {
        int p = price.top();
        price.pop();
        p /= 2;
        price.push(p);
    }
    
    long long ans = 0;
    while (!price.empty()) {
        ans += price.top();
        price.pop();
    }
    cout << ans << '\n';
}
