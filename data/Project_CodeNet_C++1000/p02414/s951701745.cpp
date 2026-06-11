#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n, m, l;
    cin >> n >> m >> l;

    long aryA[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> aryA[i][j];
            // cout << aryA[i][j] << endl;
        }
    }

    long aryB[m][l];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < l; j++){
            cin >> aryB[i][j];
            // cout << aryB[i][j] << endl;
        }
    }

    long long aryC[n][l];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){

            // printf("(%d * %d) + (%d * %d) \n", aryA[i][0], aryB[0][j], aryA[i][1], aryB[1][j] );

            // aryC[i][j] = (aryA[i][0] * aryB[0][j]) + (aryA[i][1] * aryB[1][j]);
            // cout << aryC[i][j];
            // if(j != l - 1){
            //     cout << " ";
            // }
            aryC[i][j] = 0;
            for(int k = 0; k < m; k++){
                // cout << (long)aryA[i][k] * (long)aryB[k][j] << endl;
                aryC[i][j] += (aryA[i][k] * aryB[k][j]);
                // cout << aryC[i][j] << endl;
            }
            cout << aryC[i][j];
            if(j != l - 1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
