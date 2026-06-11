#include<iostream>
using namespace std;

int main(){
    int m, n;
    cin >> n >> m;

    int A[n][m] = {};
    int b[m] = {};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    for (int k = 0; k < m; k++){
        cin >> b[k];
    }

    for (int l = 0; l < n; l++){
        int x = 0;
        for (int s = 0; s < m; s++){
            x += A[l][s] * b[s];
        }
        cout << x << endl;
    }

    return 0;
}
