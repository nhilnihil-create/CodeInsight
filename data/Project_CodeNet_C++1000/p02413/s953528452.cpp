#include <iostream>
using namespace std;
int main(void){
    int r, c, HYOU[101][101]={}, i, j;
    
    cin >> r >> c;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            cin >> HYOU[i][j];
            HYOU[i][c] += HYOU[i][j];
            HYOU[r][j] += HYOU[i][j];
            HYOU[r][c] += HYOU[i][j];
        }
    }
    
    for(i=0; i<r+1; i++){
        for(j=0; j<c+1; j++){
            cout << HYOU[i][j];
            if(j != c)   cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
