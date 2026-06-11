#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int arr[r+1][c+1] = {}, i, j;

    for(i=0; i<r; ++i) {
        for(j=0; j<c; ++j) {
            cin >> arr[i][j];
        }
    }

    for(i=0; i<r; ++i) {
        for(j=0; j<c; ++j) {
            arr[i][c] += arr[i][j];
        }
    }

    for(j=0; j<c+1; ++j) {
        for(i=0; i<r; ++i) {
            arr[r][j] += arr[i][j];
        }
    }

    for(i=0; i<r+1; ++i) {
        cout << arr[i][0];
        for(j=1; j<c+1; ++j) {
            cout << ' ' << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}