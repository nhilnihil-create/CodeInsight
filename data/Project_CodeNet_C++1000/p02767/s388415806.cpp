#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    int X[N], s = 0;
    for(size_t i = 0; i < N; ++i) {
        cin >> X[i];
        s += X[i];
    }

    int P1 = s / N, P2 = s / N + 1;

    int ans1 = 0, ans2 = 0;
    for(size_t i = 0; i < N; ++i) {
        ans1 += (X[i] - P1)*(X[i] - P1);
        ans2 += (X[i] - P2)*(X[i] - P2);
    }

    cout << min(ans1, ans2) << endl;
    
    return 0;
}