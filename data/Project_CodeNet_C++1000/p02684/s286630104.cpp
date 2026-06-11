#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    ll roop = 1;
    ll city = 0;
    ll num = 0;
    ll roop_start;
    vector<ll> visited(N, -1);
    while (num < N) {
        if (visited[city] != -1) {
            roop = num - visited[city];
            break;
        }
        if (num == K) goto Exit;
        visited[city] = num;
        city = A[city];
        num++;
    }
    roop_start = num - roop;
    K = (K - roop_start) % roop;
    city = 0;
    for (ll i = 0; i < K + roop_start; i++) {
        city = A[city];
    }
Exit:
    cout << ++city << endl;
    return 0;
}
