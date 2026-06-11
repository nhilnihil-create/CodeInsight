#include<iostream>
#include<string.h>
using namespace std;
int p[300000];
int main(){
    memset(p,0,sizeof(p));
    for(int i=2;i<253456;i++)
        for(int j=2;i*j<253456;j++)
            p[i*j]=1;
    int n,ans;
    while(cin>>n,n){
        ans=0;
        for(int i=n+1;i<=2*n;i++)
            if(p[i]==0)ans++;
        cout<<ans<<endl;
    }
    return 0;
}