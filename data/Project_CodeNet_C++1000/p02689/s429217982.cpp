#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,ans=0,a,b;
    cin>>n>>m;
    int h[n];
    bool ig[n];
    for(int i=0;i<n;i++)ig[i]=true;
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(h[a-1]<=h[b-1])ig[a-1]=false;
        if(h[a-1]>=h[b-1])ig[b-1]=false;
    }
    for(int i=0;i<n;i++){
        if(ig[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}