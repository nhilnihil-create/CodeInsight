#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        q.push(k);
    }
    while(m) {
        ll a1 = q.top();
        q.pop();
        q.push(a1/ 2);
        m--;
    }
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ret += q.top();
        q.pop();
    }
    cout << ret << endl;
    return 0;
}