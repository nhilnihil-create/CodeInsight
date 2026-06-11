#include <iostream>
using namespace std;
int main(void){

    int n,m;
    
    cin >> n >> m;
    
    int A[n][m];
    int b[m];
    int c;
    
    int d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> d;
            A[i][j]=d;
        }
    }
    for(int j=0;j<m;j++){
        cin >> d;
        b[j]=d;
    }

    for(int i=0;i<n;i++){
        c=0;
        for(int j=0;j<m;j++){
            c += (A[i][j] * b[j]);
        }
        cout << c << endl;
    }
    return 0;
}

