#include<iostream>
using namespace std;
int main(void){
    int n,m,l;
    int i,j,k;
    cin >> n >> m >>l;
    int M1[n][m],M2[m][l];
    long lSum;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin >> M1[i][j];
        }
    }
    for (i=0;i<m;i++){
        for (j=0;j<l;j++){
            cin >> M2[i][j];
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<l;j++){
            if (j!=0){
                cout << ' ';
            }
            lSum=0;
            for (k=0;k<m;k++){
                lSum+=M1[i][k]*M2[k][j];
            }
            cout << lSum;
        }
        cout << endl;
    }
    
}
