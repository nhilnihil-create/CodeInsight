#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll N;
    cin >> N;

    priority_queue<ll, vector<ll>, greater<ll>> v;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        v.push(tmp);
    }

    long double sum = 0;
    sum += (long double)v.top() / pow(2, N - 1);
    v.pop();
    sum += (long double)v.top() / pow(2, N - 1);
    v.pop();
    REP(i, N - 2) {
        sum += (long double)v.top() / pow(2, N - (i + 2));
        v.pop();
    }
    cout << sum << endl;

    return 0;
}