#include <bits/stdc++.h>
using namespace std;

int main(){
    int board[3][3];
    int n;
    int mark[10];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> board[i][j];   
        }
        
    }

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> mark[i];    
    }

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(mark[i]==board[j][k]){
                    board[j][k]= -1;
                }
            }   
        }
        
    }

    bool ans = false;
    
    for (int i = 0; i < 3; i++){
        if(board[i][0]==-1 && board[i][1]==-1 && board[i][2]==-1){
            ans = true;
        }
    }
    for (int i = 0; i < 3; i++){
        if(board[0][i]==-1 && board[1][i]==-1 && board[2][i]==-1){
            ans = true;
        }
    }
    if(board[0][0]==-1 && board[1][1]==-1 && board[2][2]==-1){
        ans = true;
    }
    if(board[0][2]==-1 && board[1][1]==-1 && board[2][0]==-1){
        ans = true;
    }

    if(ans){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    

    
}