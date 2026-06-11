#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    bool flag=true,flag2=true;
    int ans=0;
    for(int i=0;i<=n+1||flag2;i++){
        int s=x-i;
        flag=true;
        for(int j=0;j<n;j++){
            if(p[j]==s){
                flag=false;
                break;
            }
        }
        if(flag&&flag2){
            ans=s;
            flag2=false;
        }
        flag=true;
        s=x+i;
        for(int j=0;j<n;j++){
            if(p[j]==s){
                flag=false;
                break;
            }
        }
        if(flag&&flag2){
            ans=s;
            flag2=false;
        }
    }
    cout<<ans<<"\n";
    return(0);
}