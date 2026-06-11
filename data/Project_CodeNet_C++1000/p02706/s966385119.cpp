#include <bits/stdc++.h>
using namespace std;

long N, M;

int main(void) {

    cin >> N >> M;

    for (long i = 0; i < M; i++) {
        long a; cin >> a;
        N -= a;
    }

    cout << (N < 0 ? -1 : N) << endl;

    return 0;

}