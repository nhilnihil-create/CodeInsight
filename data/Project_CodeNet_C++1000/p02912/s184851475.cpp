#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    ll a;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        pq.push(a);
    }
    
    ll b;
    for (int i = 0; i < m; i++) {
        b = pq.top();
        pq.pop();
        pq.push(b / 2);
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}