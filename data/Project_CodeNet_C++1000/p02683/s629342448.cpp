#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,x,ans=INT_MAX;
    cin>>n>>m>>x;
    int c[n],a[n][m];
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++)cin>>a[i][j];
    }
    for(int i=1;i<pow(2,n);i++){
        int cost=0,skill[m],count=0;
        for(int j=0;j<m;j++)skill[j]=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                cost+=c[j];
                for(int k=0;k<m;k++)skill[k]+=a[j][k];
            }
        }
        for(int j=0;j<m;j++){
            if(skill[j]>=x)count++;
        }
        if(count==m){
            if(ans>cost)ans=cost;
        }
    }
    if(ans==INT_MAX)cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}