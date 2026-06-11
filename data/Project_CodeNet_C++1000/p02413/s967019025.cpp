#include <iostream>
using namespace std;

int main() {
    int r, c;
    int excel[101][101];
    for (int i=0; i<101;i++)
        for (int j=0; j<101; j++) excel[i][j] = 0;

    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> excel[i][j];
            int point = excel[i][j];
            excel[i][c] += point;
            excel[r][j] += point;
            excel[r][c] += point;
        }
    }

    for (int i=0; i<=r; i++) {
        for (int j=0; j<=c; j++) {
            cout << excel[i][j];
            if ( j != c ) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}