#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << (x) << "( (L" << __LINE__ << ")" << endl;
using namespace std;

#define ll long long

ll n,m;
int main() {
    priority_queue<ll> q;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        q.push(tmp);
    }
    for(ll i = 0; i < m; i++) {
        ll tmp = q.top();
        q.pop();
        q.push(tmp / 2);
    }
    ll result = 0;
    while(!q.empty()) {
        result += q.top();
        q.pop();
    }
    cout << fixed << result;
}