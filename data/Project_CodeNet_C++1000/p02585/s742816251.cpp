#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll t;
t=1;
//cin>>t;
while(t--){
ll n,k;
cin>>n>>k;
ll p[n+1], c[n+1];
ll ki=k;
for(int i=1; i<=n;i++)
cin>>p[i];

for(int i=1; i<=n;i++)
cin>>c[i];

ll ans=-9000000000000000000;

for(int i=1; i<=n;i++){
    
    k = ki;
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    ll j=i;
    ll temp=0;
    ll co=0;;
    while(vis[p[j]]!=1){
        j = p[j];
         vis[j]=1;
        temp+=c[j];
        co++;
        ans=max(temp,ans);
        //cout<<c[j]<<' ';
         if(co==k){
        ans=max(temp,ans);
            break;
         }
         
    }

   // cout<<temp<<endl;
    
   if(co==k)
   continue;
    
    if(k%co==0){
        temp= temp*(k/co-1);
        k=co;
    }else {
    temp= temp*(k/co);
    k= k%co;
    }
    while(k){
     ans=max(temp,ans);
       j = p[j];
        vis[j]=1;
        temp+=c[j];
        k--;
    }
ans=max(temp,ans);
}
cout<<ans;
}

}