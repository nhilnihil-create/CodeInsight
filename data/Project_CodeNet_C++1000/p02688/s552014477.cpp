#include<iostream>
using namespace std;

int main() {
    int N, K, t;
    int d[110];
    int A[110] = {};

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> d[i];
        for (int j = 0; j < d[i]; j++) {
            cin >> t;
            A[t-1] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) if (A[i] == 0) ans++;
    cout << ans << endl;

}