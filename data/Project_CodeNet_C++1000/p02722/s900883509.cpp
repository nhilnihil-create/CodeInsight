#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main(){
   ll n;
   cin>>n;
   bool a[1010101]={};
   ll n2=(ll)sqrt(n),ans=0;
   for(ll i=2;i<=n2;i++){
      ll f=n;
      while(f%i==0)f/=i; 
      if(f%i==1){ans++;}
      //else{a[i]=1;}
   }
   ll z=n;
   for(ll i=2;(n)/i>n2;i++){
       if((n)%i==1)ans++;
   }
   if(n==2)cout<<1<<endl;
   else cout<<ans+2<<endl;
   
   

}
