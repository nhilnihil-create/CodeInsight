#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

int N;
const int MAX_N = 2.0e5 + 10;
ll A[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    ll cnt = 0;
    for (int i = 1; i < N; i++) {
        if (A[i-1] > A[i]) {
            cnt += A[i-1] - A[i];
            A[i] = A[i-1];
        }
    }

    cout << cnt << endl;

    return 0;
}
