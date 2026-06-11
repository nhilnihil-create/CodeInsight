#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    vector<vector<int>> card(3,vector<int>(3));
    for (int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> card[i][j];
        }
    }
    int N;
    cin >> N;
    vector<int> appear(N);
    for (int i=0;i<N;i++) {
        cin >> appear[i];
    }
    vector<vector<bool>> bingo(3,vector<bool>(3,false));
    for (int i=0;i<N;i++) {
        for (int j=0;j<3;j++) {
            for (int k=0;k<3;k++) {
                if (appear[i]==card[j][k]) {
                    bingo[j][k]=true;
                }
            }
        }
    }
    
    string ans="No";
    for(int i=0;i<3;i++) {
            if(bingo[i][0]&&bingo[i][1]&&bingo[i][2]) {
                ans="Yes";
            }
            if(bingo[0][i]&&bingo[1][i]&&bingo[2][i]) {
                ans="Yes";
            }
    }   
            if(bingo[0][0]&&bingo[1][1]&&bingo[2][2]) {
                ans="Yes";
            }
            if(bingo[0][2]&&bingo[1][1]&&bingo[2][0]) {
                ans="Yes";
            }
        
    
    cout << ans << endl;
    
}
