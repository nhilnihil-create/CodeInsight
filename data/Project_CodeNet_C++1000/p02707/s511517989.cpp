#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5+5;

int A[MX];

int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    for (int i = 2; i <= N; ++i) {
        int x; cin >> x;

        A[x]++;
    }

    for (int i = 1; i <= N; ++i) {
        cout << A[i] << "\n";
    }

}
