#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    ll N, K;
    cin >> N >> K;
    vector<ll> teleport(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> teleport[i];
    }

    ll now = 1;
    ll step = 1;
    ll loop_begin = 0;
    ll loop_len = 0;
    vector<ll> visited(N + 1, -1);

    visited[1] = 0;
    while (K-- > 0) {
        now = teleport[now];
        if (visited[now] > 0) {
            loop_begin = now;
            loop_len = step - visited[now];
            break;
        }
        visited[now] = step++;
    }

    if (loop_begin == 0) {
        cout << now << endl;
        return 0;
    }

    ll r = K % loop_len;
    while (r-- > 0) {
        now = teleport[now];
    }
    cout << now << endl;
}
