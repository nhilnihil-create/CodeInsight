#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
int main() {
    ull N, M;
    cin >> N >> M;
    priority_queue<ll> q;
    rep(i, N) {
        ll tmp;
        cin >> tmp;
        q.push(tmp);
    }
    rep(i, M) {
        ll num = q.top();
        q.pop();
        num /= 2;
        q.push(num);
    }

    ll sum = 0;

    while(!q.empty()) {
        sum += q.top();
        q.pop();
    }
    cout << sum << endl;
}