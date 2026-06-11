#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int d, A;
    int sunuke[N] = {0};
    for (int i = 0; i < K; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> A;
            sunuke[A - 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (sunuke[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}