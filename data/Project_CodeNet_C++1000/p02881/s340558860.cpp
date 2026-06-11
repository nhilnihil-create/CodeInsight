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
ll n,m,i,x,j,mx=0,t,k,b=0,a=0,ans=0,c=0; 
ll mn;    
 st s,str; char strn;
cin>>n; //a=n; n-=1; 
    mn=n-1;
ll ara[n+1],bra[n+1],taj[n+1];
//memset(ara,0,sizeof(ara));
//for(i=1;i<=n;i++) cin>>ara[i]; 
      // cout<<k<<endl;  
  for(i=1;i<=sqrt(n);i++)
   {
     if(n%i==0)
     {
        b++;
      //ara[++a]=i;
     // bra[++b]=n/i;  
      ans=((n/i)+i)-2;
      mn=min(mn,ans);                   
     }
   }      
// t=ara[a]-1;
// k=bra[b]-1; 
  if(!b)cout<<n-1;     
 else cout<<mn<<endl;
    
 
    rt;
}
