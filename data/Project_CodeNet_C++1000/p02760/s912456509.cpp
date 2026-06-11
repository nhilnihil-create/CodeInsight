#include<bits/stdc++.h>
using namespace std;   
int main(){
    int c[5][5],n;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>c[i][j];
        }
    }
    cin>>n;
    int b;
    bool a[5][5]={};
    for(int i=0;i<n;i++){
        cin>>b;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(c[j][k]==b){
                    a[j][k]=true;
                }
            }
        }
    }
    if(a[0][0]&&a[0][1]&&a[0][2]||a[1][0]&&a[1][1]&&a[1][2]||a[2][0]&&a[2][1]&&a[2][2]||a[0][0]&&a[1][0]&&a[2][0]||a[0][1]&&a[1][1]&&a[2][1]||a[0][2]&&a[1][2]&&a[2][2]||a[0][0]&&a[1][1]&&a[2][2]||a[2][0]&&a[1][1]&&a[0][2]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}