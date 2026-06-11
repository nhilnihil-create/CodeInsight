#include <bits/stdc++.h>
using namespace std;

long N;
map<long, long> M;

int main(void) {

    cin >> N;
    for (long i = 1; i < N; i++) {
        long a; cin >> a;
        M[a]++;
    }

    for (long i = 1; i <= N; i++) {
        cout << M[i] << endl;
    }

    return 0;

}