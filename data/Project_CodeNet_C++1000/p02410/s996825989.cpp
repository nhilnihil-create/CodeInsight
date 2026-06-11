#include<iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n,m;
    int a[100][100];
    int b[100];
    int i,j;
    int ans=0;
    
    cin >> n >> m;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            cin >> a[i][j];    
        }
    }
    
    for (i = 0; i < m; i++){
        cin >> b[i];
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            ans = ans + a[i][j] * b[j];
        }
        cout << ans << endl;
        ans = 0;
    }
    
    return 0;
}