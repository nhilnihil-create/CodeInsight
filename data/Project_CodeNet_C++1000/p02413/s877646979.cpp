#include<iostream>
using namespace std;
int main () {
    int r,c,sum;
    
    cin >> r >> c;
    
    int mat[100][100] = {{}};
    
    int row[100] = {};
    
    int column[100] = {};
    
    for (int i = 0; i < r; i ++) {
        
        for (int j = 0; j < c; j ++) {
            
            cin >> mat[i][j];
            
            row[i] += mat[i][j];
            
        }
    }
    
    for (int i = 0; i < c; i ++) {
        
        for (int j = 0; j < r; j ++) {
            
            column[i] += mat[j][i];
            
        }
        
        sum += column[i];
        
    }
    
    for (int i = 0; i < r; i ++) {
        
        for (int j = 0; j < c; j ++) {
            
            cout << mat[i][j] << ' ';
            
        }
        
        cout << row[i] << endl;
        
    }
    
    for (int i = 0; i < c; i ++) {
        
        cout << column[i] << ' ';
        
    }
    
    cout << sum << endl;
    
    return 0;
    
}
