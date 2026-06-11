#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int p[M];
    string S[M];
    for (int i = 0; i < M; i++) cin >> p[i] >> S[i];

    bool isOK[N + 1] = {false};
    int arrWA[N + 1] = {0};
    for (int i = 0; i < M; i++) {
        if (isOK[p[i]]) continue;
        if (S[i] == "AC") {
            isOK[p[i]] = true;
        }
        else {
            arrWA[p[i]]++;
        }
    }

    int countAC = 0;
    int countWA = 0;
    for (int i = 1; i < N + 1; i++) {
        if (isOK[i]) {
            countAC++;
            countWA += arrWA[i];
        }
    }

    cout << countAC << " " << countWA << endl;
    return 0;
}