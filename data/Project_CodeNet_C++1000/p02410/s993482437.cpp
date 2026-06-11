#include <iostream>
using namespace std;

int main(){
    int a[1000][1000],b[1000];
    int n, m, h;
    int i, j;
    
    
    cin >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for(j = 0; j < m; j++) cin >> b[j];
    
    for(i = 0; i < n; i++){
        h = 0;
        for(j = 0; j < m; j++){
            h += a[i][j]*b[j];
        }
        cout << h << endl;
    }
    
    return 0;
}
