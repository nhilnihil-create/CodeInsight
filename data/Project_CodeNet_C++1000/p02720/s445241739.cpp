#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int K;
    cin >> K;

    vector<ll> ans;
    queue<ll> que;
    for (int i = 1; i <= 9; ++i) {
        que.push(i);
        ans.push_back(i);
    }

    while (ans.size() < 100005) {
        ll n = que.front();
        que.pop();

        ll next = n % 10 - 1;
        if (next >= 0) {
            que.push(n * 10 + next);
            ans.push_back(n * 10 + next);
        }
        next = n % 10;
        que.push(n * 10 + next);
        ans.push_back(n * 10 + next);
        next = n % 10 + 1;
        if (next <= 9) {
            que.push(n * 10 + next);
            ans.push_back(n * 10 + next);
        }
    }

    cout << ans[K - 1] << endl;
}