#include <iostream>
using namespace std;
int c[10][10];

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 10 == 0) continue;
        int l = i, r;
        while (l > 9) l /= 10;
        r = i % 10;
        c[l-1][r-1]++;
    }
    int ans = 0; 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ans += c[i][j] * c[j][i];
        }
    }
    cout << ans << endl;
}
