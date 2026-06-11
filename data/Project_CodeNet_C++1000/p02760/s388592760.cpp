#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3][3]={},b[3][3]={};
    for(int i=0;i<3;i++){//ビンゴカード
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    int n,num;
    cin >> n;
    
    for(int k=0;k<n;k++){//ナンバー
        cin >> num;
        for(int i=0;i<3;i++){//ビンゴカードとナンバーの整合確認
            for(int j=0;j<3;j++){
                if(a[i][j]==num){
                    b[i][j] = 1;//穴あけ
                }
            }
        } 
    }
    int count = 0;
    if(b[0][0]==b[1][1]&&b[1][1]==b[2][2]&&b[2][2]==1){
        count++;
    }
    if(b[0][2]==b[1][1]&&b[1][1]==b[2][0]&&b[2][0]==1){
        count++;
    }
    for(int i=0;i<3;i++){//ビンゴカードとナンバーの整合確認
        if(b[i][0]==b[i][1]&&b[i][1]==b[i][2]&&b[i][2]==1){
            count++;
        }
        for(int j=0;j<3;j++){
            if(b[0][j]==b[1][j]&&b[1][j]==b[2][j]&&b[2][j]==1){
                count++;
            }
        }
    }

    if(count>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}