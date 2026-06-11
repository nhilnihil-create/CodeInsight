#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    int maxDist = K - A[N - 1] + A[0];
    for (int i = 1; i < N; i++) {
        maxDist = max(maxDist, A[i] - A[i - 1]);
    }
    cout << K - maxDist << endl;
    return 0;
}