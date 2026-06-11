#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
    int N, A[200005];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll d = 0;
        if (i > 0) {
            if (A[i - 1] >= A[i]) {
                d = A[i - 1] - A[i];
                A[i] += d;
            }
        }
        ans += d;
    }
    cout << ans << endl;

    return 0;
}