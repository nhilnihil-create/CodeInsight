#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a[3][3];
    bool flag=false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int n;
    vector<vector<bool>>d(3,vector<bool>(3));
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(a[i][j]==x)d[i][j]=true;
        }
    }
    for(int i=0;i<3;i++){
        if(d[i][0]&&d[i][1]&&d[i][2])flag=true;
    }
    for(int i=0;i<3;i++){
        if(d[0][i]&&d[1][i]&&d[2][i])flag=true;
    }
    if(d[0][0]&&d[1][1]&&d[2][2])flag=true;
    if(d[2][0]&&d[1][1]&&d[0][2])flag=true;
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}