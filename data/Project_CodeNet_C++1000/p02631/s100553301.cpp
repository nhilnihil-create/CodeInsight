#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N;
    cin >> N;
    vector<unsigned> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    unsigned n = 0;
    for (int i = 0; i < N; i++) {
        n ^= a[i];
    }

    for (int i = 0; i < N; i++) {
        cout << (n ^ a[i]);
        if (i != N - 1) cout << " ";
        else cout << endl;
    }
}