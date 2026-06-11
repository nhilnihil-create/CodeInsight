#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    priority_queue<ll> que;
    rep(i, n) {
        cin >> a[i];
        que.push(a[i]);
    }
    ll tmp;
    rep(i, m) {
        tmp = que.top();
        que.pop();
        que.push(tmp/2);
    }
    ll fee = 0;
    while (!que.empty()) {
        fee += que.top();
        que.pop();
    }
    cout << fee << endl;


    return 0;
}