#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000000+7;

int main() {
    ll N, K;
    ll before, after, ans;
    after = 0;
    before = 0;
    ans = 0;
    cin >> N >> K;
    vector<ll>A(N);

    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for (ll i = 0; i < N-1; i++) {
        for (ll j = i+1; j < N; j++) {
            if (A[i] == A[j]) continue;
            if (A[i] > A[j]) ans = (ans+(K+1)*K/2)%MOD;
            else ans = (ans+(K-1)*K/2)%MOD;
        }
    }
    cout << ans << endl;
}
