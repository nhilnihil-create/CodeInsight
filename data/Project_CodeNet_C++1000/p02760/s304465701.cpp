#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[9];
    for (int i = 0; i < 9; i++) cin >> A[i];
    int N;
    cin >> N;
    int b[N];
    for (int i = 0; i < N; i++) cin >> b[i];

    bool bingo[9] = {false};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == b[j]) {
                bingo[i] = true;
                break;
            }
        }
    }
    string ans = "No";
    if ((bingo[0] && bingo[1] && bingo[2])
     || (bingo[3] && bingo[4] && bingo[5])
     || (bingo[6] && bingo[7] && bingo[8])) {
        ans = "Yes";
    }
    else if ((bingo[0] && bingo[3] && bingo[6])
     || (bingo[1] && bingo[4] && bingo[7])
     || (bingo[2] && bingo[5] && bingo[8])) {
         ans = "Yes";
    }
    else if ((bingo[0] && bingo[4] && bingo[8])
     || (bingo[2] && bingo[4] && bingo[6])) {
         ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}