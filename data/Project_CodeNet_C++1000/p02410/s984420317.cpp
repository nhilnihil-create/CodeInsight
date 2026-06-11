#include<iostream>
using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;
    int gyoretsu[100][100] = {{}};
    int retsubekutoru[100] = {};
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> gyoretsu[i][j];
        }
    }
    for (int k = 0; k < m; k++){
        cin >> retsubekutoru[k];
    }
    
    for (int a = 0; a < n; a++){
        int x = 0;
        for (int b = 0; b < m; b++){
            x += gyoretsu[a][b] * retsubekutoru[b];
        }
        cout << x << endl; 
    }
    return 0;
}

