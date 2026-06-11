#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int m = 4; m <= M; m++) {
        for (int d1 = 2; d1 <= 9; d1++) {
            for (int d10 = 2; d10 <= 9; d10++) {
                int d = d1 + d10 * 10;
                if (d <= D && m == d1 * d10) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}