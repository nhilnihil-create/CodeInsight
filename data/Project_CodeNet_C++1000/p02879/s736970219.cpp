#include<bits/stdc++.h>
#define ll long long int
#define st string
#define con continue
#define br break
#define rt return 0
#define fr first
#define sec second
using namespace std;
int main(){
//ll tc; cin>>tc; while(tc--){
ll n,m,mn=INT_MAX,i,x,j,a=0,t,k,b=-1,mx=-1,cnt=0,c=0; 
 st s,str; char strn;
cin>>n>>m; //a=n; n-=1; 
ll ara[n+1],bra[n+1],taj[n+1];
memset(ara,0,sizeof(ara));
//for(i=1;i<=n;i++) cin>>ara[i]; 
  /*for(i=1;i<=9;i++)
   {  
     for(j=1;j<=9;j++)
      {
        if(i*j==n)
           {
            cout<<"Yes";
               rt;
             }
        }
      
      
   } */     
  
   if(n>=10 || m>=10) cout<<-1<<endl;    
  else   cout<<n*m<<endl;
    
 
    rt;
}