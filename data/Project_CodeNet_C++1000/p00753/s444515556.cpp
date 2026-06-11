#include<bits/stdc++.h>
using namespace std;

bool f[300000];
int main(){
    fill_n(f,300000,true);
    f[0]=f[1]=false;
    for(int i=0;i<300000;i++){
        if(!f[i])continue;
        for(int j=2;i*j<300000;j++)f[i*j]=false;
    }

    int n;
    while(cin>>n,n){
        int cnt=0;
        for(int i=n+1;i<=n*2;i++)cnt+=f[i];

        cout<<cnt<<endl;
    }
    return 0;
}