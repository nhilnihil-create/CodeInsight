#include <bits/stdc++.h>
using namespace std;

int main(){
    //IO
    int a[9];
    int i, j;
    for (i = 0; i<9 ; i++){cin >> a[i];}
    int n;
    cin >> n;
    int b[n];
    for (i = 0; i<9 ; i++){cin >> b[i];}
    
    //calculate
    int row1, row2, row3;
    int col1, col2, col3;
    int dia1, dia2;
    int c[9]={0};
    for (i = 0; i<9; i++){
        for (j = 0; j<n; j++){
            if(a[i] == b[j]){c[i] += 1;}
        }
    }
    
    row1 = c[0]+c[1]+c[2];
    row2 = c[3]+c[4]+c[5];
    row3 = c[6]+c[7]+c[8];
    col1 = c[0]+c[3]+c[6];
    col2 = c[1]+c[4]+c[7];
    col3 = c[2]+c[5]+c[8];
    dia1 = c[0]+c[4]+c[8];
    dia2 = c[2]+c[4]+c[6];
    if (row1 >= 3 || row2 >= 3 || row3 >= 3 || col1 >= 3 || col2 >= 3 || col3 >= 3 || dia1 >=3 || dia2 >= 3){
        std::cout << "Yes" << std::endl;
    }
    else{std::cout << "No" << std::endl;}
}