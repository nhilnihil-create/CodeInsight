#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, cnt = 0;
    string S;
    cin >> N;
    cin >> S;
    char C1, C2, C3;

    for (int i = 0; i < S.size() - 2; ++i) {
        C1 = S[i];
        C2 = S[i + 1];
        C3 = S[i + 2];
        if (C1 == 'A' && C2 == 'B' && C3 == 'C')cnt++;
    }

    cout << cnt << endl;

}