#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);

    rep(i, N) { cin >> A[i]; }

    int cnt = 0;
    while (true) {
        vector<ll> sum(N + 1, 0);
        bool judge = 1;
        rep(i, N) {
            int a = A[i];
            int left = max(0, i - a);
            int right = min(N, i + a + 1);
            sum[left] += 1;
            sum[right] -= 1;
        }

        rep(i, N + 1) { sum[i + 1] += sum[i]; }

        rep(i, N) {
            A[i] = sum[i];
            if (A[i] != N)
                judge = 0;
        }

        cnt++;
        if (cnt == K || judge) {
            rep(i, N) { cout << A[i] << " "; }
            return 0;
        }
    }
}