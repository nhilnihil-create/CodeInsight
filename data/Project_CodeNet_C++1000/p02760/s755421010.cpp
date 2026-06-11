#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N;
    int A[3][3];
    int check[3][3] = {{0},{0}};
    bool bingo = false;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> A[i][j];
        }
    }
    
    cin >> N;
    for(int i=0;i<N;i++){
        int b;
        cin >> b;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(A[j][k] == b){
                    check[j][k]++;
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        if(check[i][0] == 1 && check[i][1] == 1 && check[i][2] == 1){
            bingo = true;
            break;
        }
        if(check[0][i] == 1 && check[1][i] == 1 && check[2][i] == 1){
            bingo = true;
            break;
        }
    }
    if(check[0][0] == 1 && check[1][1] == 1 && check[2][2] == 1 || check[0][2] == 1 && check[1][1] == 1 && check[2][0] == 1){
        bingo = true;
    }
    if(bingo){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
