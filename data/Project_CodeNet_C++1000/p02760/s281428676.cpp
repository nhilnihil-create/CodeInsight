#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)cin >> a[i][j];
    }
    int n;
    cin >> n;
    vector<int>b(n);
    for(int i=0;i<n;i++)cin >> b[i];
    vector<vector<bool>>ccc(3,vector<bool>(3,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[j][k] == b[i]){
                    ccc[j][k] = true;
                }
            }
        }
    }
    bool chkk = false;
    for(int i=0;i<3;i++){
        bool chkkk = true;
        bool chkkkk = true;
        for(int j=0;j<3;j++){
            if(ccc[i][j]==false){
                chkkk = false;
            }

            if(ccc[j][i]==false){
                chkkkk = false;
            }
        }
        if(chkkk||chkkkk){
            chkk = true;
        }
    }
    if(ccc[0][0] && ccc[1][1] && ccc[2][2])chkk=true;
    if(ccc[0][2] && ccc[1][1] && ccc[2][0])chkk=true;

    if(chkk){
        cout << "Yes"<<endl;
        
    }else cout<<"No"<<endl;

}