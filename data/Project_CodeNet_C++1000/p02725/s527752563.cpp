#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int K,n;
int dis[200010];
int main(){
    //freopen("data.in","r",stdin);
    cin>>K>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&dis[i]);
    int dis_n=dis[n];
    for(int i=n;i>1;i--) 
        dis[i]=dis[i]-dis[i-1];
    dis[1]+=K-dis_n;
    int mx=0,ans;
    for(int i=1;i<=n;i++){
        mx=max(mx,dis[i]);
        ans+=dis[i];
    }
    cout<<ans-mx<<endl;
    
}