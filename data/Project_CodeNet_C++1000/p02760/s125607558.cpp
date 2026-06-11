#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5][5];
    int n,b,flag=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cin>>a[i][j];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]==b){
                    a[i][j]=0;
                    flag=1;
                    break;
                }
            }
            if(flag==1){ flag=0; break; }
        }
    }

    flag=0;

    if(a[0][0]==a[0][1] && a[0][1]==a[0][2]) flag=1;
    if(a[0][0]==a[1][0] && a[1][0]==a[2][0]) flag=1;
    if(a[0][2]==a[1][2] && a[1][2]==a[2][2]) flag=1;
    if(a[2][0]==a[2][1] && a[2][1]==a[2][2]) flag=1;
    if(a[0][1]==a[1][1] && a[1][1]==a[2][1]) flag=1;
    if(a[1][0]==a[1][1] && a[1][1]==a[1][2]) flag=1;
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]) flag=1;
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0]) flag=1;
    
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}