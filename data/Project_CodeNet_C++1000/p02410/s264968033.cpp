#include<iostream>
using namespace std;
int main () {
    
    int n,m,x,c;
    
    cin >> n >> m;
    
    int amatrix[n][m] = {{0}};
    
    int bmatrix[m] = {0};
    
    
    
    for (int h1 = 0; h1 < n; h1 ++) {
        
        for (int h2 = 0; h2 < m; h2 ++) {
            
            cin >> x;
            
            amatrix[h1][h2] = x;
            
        }
        
    }
    
    for (int h3 = 0; h3 < m; h3 ++) {
        
        cin >> x;
            
        bmatrix[h3] = x;
        
    }
    
    for (int i = 0; i < n; i ++) {
        
        c = 0;
        
        for (int j = 0; j < m; j ++) {
            
            c += amatrix[i][j] * bmatrix[j];
            
        }
        
        cout << c << endl;
        
    }
    
    return 0;
    
}

