#include <bits/stdc++.h>
using namespace std;

long N, ans;
map<long, long> X, Y;

int main(void) {

    cin >> N;
    for (long i = 0; i < N; i++) {
        long a; cin >> a;
        X[i+a]++;
        Y[i-a]++;
    }

    for (auto x: X) {
        ans += x.second * Y[x.first];
    }

    cout << ans << endl;

    return 0;

}