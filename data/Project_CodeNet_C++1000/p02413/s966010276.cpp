
#include<iostream>
using namespace std;

int main() {
        int s[101][101], r, c, i, j;
        cin >> r >> c;
        for (i = 0; i < r + 1; i++) {
                for (j = 0; j < c + 1; j++) {
                        s[i][j] = 0;
                }
        }
        for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                        cin >> s[i][j];
                }
        }
        for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                        s[i][c] += s[i][j];
                }
        }
        for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                        s[r][j] += s[i][j];
                }
        }
        for (i = 0; i < r; i++) {
                s[r][c] += s[i][c];
        }
        for (i = 0; i < r + 1; i++) {
                for (j = 0; j < c + 1; j++) {
                        cout << s[i][j];
                        if (j != c) cout << " ";
                        else cout << endl;
                }
        }
}