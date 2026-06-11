#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    queue<string> q;
    q.push("a");
    while (q.front().length() < n) {
        string now = q.front();
        q.pop();
        char biggest = now[0];
        rep(i, now.length()) { biggest = max(biggest, now[i]); }
        for (char next = 'a'; next <= biggest + 1; next++) {
            q.push(now + next);
        }
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}

