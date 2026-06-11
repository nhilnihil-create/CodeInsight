#include <bits/stdc++.h>
using namespace std;

long N, K, ans;
vector<long> A;

int main(void) {

    cin >> N >> K;
    A.resize(N, 0);

    for (long i = 0; i < K; i++) {
        long d; cin >> d;
        for (long j = 0; j < d; j++) {
            long a; cin >> a; a--;
            A[a]++;
        }
    }

    for (auto e: A) {
        if (e == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}