#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int modpow(int x,int n){
  if(n==0){return 1;}
  int64_t sum=modpow(x,n/2);sum%=mod;
  sum*=sum;sum%=mod;
  if(n%2!=0){sum*=x;}sum%=mod;
  return sum;
}

int choose(int n,int a){
  int64_t up=1,down=1;
  for(int i=0;i<a;i++){
    up*=n-i;
    up%=mod;
    down*=i+1;
    down%=mod;
  }
  int64_t s=up*modpow(down,mod-2);
  s%=mod;
  return s;
}

int main() {
  int64_t n,a,b;
  cin>>n>>a>>b;
  int ans=modpow(2,n)-1;
  ans-=choose(n,a);if(ans<0){ans+=mod;}
  ans-=choose(n,b);if(ans<0){ans+=mod;}
  cout<<ans<<endl;
  return 0;  
}