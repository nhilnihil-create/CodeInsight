#include <iostream>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int i, j, k;
    long int arr1[n][m], arr2[m][l], arr3[n][l] = {};

    for(i=0; i<n; ++i) {
        for(j=0; j<m; ++j) {
            cin >> arr1[i][j];
        }
    }

    for(i=0; i<m; ++i) {
        for(j=0; j<l; ++j) {
            cin >> arr2[i][j];
        }
    }

    for(i=0; i<n; ++i) {
        for(j=0; j<l; ++j) {
            for(k=0; k<m; ++k) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for(i=0; i<n; ++i) {
        cout << arr3[i][0];
        for(j=1; j<l; ++j) {
            cout << ' ' << arr3[i][j];
        }
        cout << endl;
    }

    return 0;
}