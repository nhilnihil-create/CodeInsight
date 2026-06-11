#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> H;

int main() {
    cin >> N >> K;
    H.resize(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    sort(H.begin(), H.end(), greater<ll>());
    ll cnt = 0;
    for (int i = K; i < N; i++) cnt += H[i];
    cout << cnt << endl;
    return 0;
}