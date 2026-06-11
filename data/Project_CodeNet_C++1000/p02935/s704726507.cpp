#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> V(N);
    for (int i=0; i<N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    float ans = 0;
    ans = (V[0] + V[1]) / 2.0;
    for (int i=2; i<N; i++) {
        ans = (ans + V[i]) / 2.0;
    }
    cout << ans << endl;
}