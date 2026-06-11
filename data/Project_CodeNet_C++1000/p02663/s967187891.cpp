#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;i++)

int zeta(int a,int b){
  if(a>=b) return a-b;
  else return b-a;
}

int main(){
  int h1,h2,m1,m2,k;
  cin>>h1>>m1>>h2>>m2>>k;
  int len=(h2-h1)*60+(m2-m1);
  int ans=0;
  ans=len-k;
  cout<<ans<<endl;
  
  return 0;
}






