#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, A, d;
    int ans = 0;
    cin >> N >> K;
    vector<int> nusuke(N + 1, 0);
    
    for (int i = 0; i < K; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> A;
            nusuke.at(A)++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (nusuke.at(i) == 0) ans++;
    }
    cout << ans << endl;
}