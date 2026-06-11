#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007LL
#define llMAX 9223372036854775807LL
#define llMIN -9223372036854775808LL
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
 
ll n,k,x,y;
 
int main(){
  ll ans=0;
  cin >> n ;
  vi a(n+1),b(n+1),c(n+1),d(n+1);
  REP(i,n+1) cin>>a[i];



  if (n==0){
    if (a[0]==1){
      cout<<1<<endl;
      return 0;
    }else{
      cout<<-1<<endl;
      return 0;
    }
  }
  


  if (a[0]!=0){
    cout<<-1<<endl;
    return 0;
  }

 
 


  ll nown=1;
  b[0]=1;
  c[0]=1;
  for(ll i=1;i<n+1;i++){
    nown=min(nown,llMAX/2)*2;
    b[i]=nown;
    nown-=a[i];
    c[i]=nown;
    if (nown<0){
      cout<<-1<<endl;
      return 0;
    }
  }

  
  d[n]=a[n];
  for(ll i=n-1;i>=0;i--){
    d[i]=d[i+1]+a[i];
  }

  for(ll i=n;i>=0;i--){
    if (b[i]<=d[i]){
      //この時点のnownとしたから数えたやつを比較
      i++;
      if (i==n+1)break;
      b[i]=d[i];
      c[i]=d[i]-a[i];
      for(ll j=i+1;j<n+1;j++){
        b[j]=d[j];
      }
      break;
      
    }
  }
  

 
  
 
 
 
  int flag=0;
  for(ll i=0;i<n+1;i++){
    ans+=b[i];
    flag+=(b[i]<=0);
    //flag+=(c[i]<0);
  }
  if (flag!=0){
    cout<<-1<<endl;
    return 0;
  }
 
 
 
  cout<<ans<<endl;
  return 0;
}
 
/*
10
0 0 1 1 2 3 5 8 28 21 34
*/