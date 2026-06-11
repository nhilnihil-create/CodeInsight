#include <iostream>
using namespace std;

int main() {

    int r, c, sum;
    int a[101][101]={0};
    cin >> r >> c;

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << a[i][j] << " ";
            a[i][c] += a[i][j];
            a[r][j] += a[i][j];
        }
        cout << a[i][c] << endl;
    }

    for (int j=0; j<c; j++){
        cout << a[r][j] << " ";
        sum += a[r][j];
    }
    cout << sum << endl;
    return 0;
}