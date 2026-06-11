#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P.at(i);

    int minv = N + 1, res = 0;
    for (int i = 0; i < N; i++) {
        minv = min(minv, P.at(i));
        if (minv == P.at(i)) res++;
    }
    cout << res << endl;
}