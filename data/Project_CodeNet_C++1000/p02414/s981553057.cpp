#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,m,l;
    cin >> n >> m >> l;
    int A[n][m];
    int B[m][l];
    int i,j,k;
    long long int c;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<l;j++){
            cin >> B[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<l;j++){
            if(j) cout << " ";
            c=0;
            for(k=0;k<m;k++) c += A[i][k]*B[k][j];
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
