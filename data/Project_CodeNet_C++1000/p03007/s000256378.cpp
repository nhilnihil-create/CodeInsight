#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pii;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());

    bool hasNeg = false;
    bool hasPos = false;
    ll abssum = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) hasPos = true;
        if (A[i] < 0) hasNeg = true;
        sum += A[i];
        abssum += abs(A[i]);
    }
    if (hasNeg && !hasPos) {
        cout << A[0] * 2 - sum << endl;
        ll t = A[0];
        for (int i = 1; i < N; i++) {
            cout << t << ' ' << A[i] << endl;
            t -= A[i];
        }
    } else if (!hasNeg && hasPos) {
        cout << sum - A[N-1] * 2 << endl;
        ll t = A[N-1];
        for (int i = 1; i < N-1; i++) {
            cout << t << ' ' << A[i] << endl;
            t -= A[i];
        }
        cout << A[0] << ' ' << t << endl;
    } else if (hasNeg && hasPos) {
        cout << abssum << endl;
        ll t = A[N-1];
        for (int i = 1; i < N; i++) {
            if (A[i] > 0) {
                cout << t << ' ' << A[i] << endl;
                t -= A[i];
            }
        }
        cout << A[0] << ' ' << t << endl;
        t = A[0] - t;
        for (int i = 0; i < N-1; i++) {
            if (A[i] <= 0) {
                cout << t << ' ' << A[i] << endl;
                t -= A[i];
            }
        }
    } else {
        cout << 0 << endl;
        for (int i = 0; i < N-1; i++) cout << "0 0" << endl;
    }
}
