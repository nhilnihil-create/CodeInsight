#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;
  
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  
  int cnt=0;
  ll x=A[0];
  while(x>0 && x%2==0){
    if(x%2==0) cnt++;
    x/=2;
  }
  
  int a=1;
  rep(i,cnt) a*=2;
  
  bool b=true;
  for(int i=1;i<n;i++){
    if(A[i]%a!=0 || (A[i]/a)%2==0) b=false;
  }
  if(b==false){
    cout<<0<<endl;
    return 0;
  }
  
  vector<ll> B(n);
  rep(i,n) B[i]=A[i]/a;
  
  ll y=1;
  rep(i,n) y=y*B[i]/gcd(y,B[i]);
  y=y*a/2;
  cout<<(m+y)/(2*y)<<endl;

  return 0;
}