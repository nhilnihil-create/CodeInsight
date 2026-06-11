#include <iostream>
using namespace std;
int main() {
    int r,c,i,j;
    cin >> r >> c;
    int sp[r+1][c+1] = {};
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            cin >> sp[i][j];
            sp[i][c] += sp[i][j];
            sp[r][j] += sp[i][j];
        }
        sp[r][c] += sp[i][c];
    }
    for (i=0;i<=r;i++) {
        for (j=0;j<c;j++) {
            cout << sp[i][j] << " ";
        }
        cout << sp[i][c] << endl;
    }
    return 0;
}