#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()



ll factorial(ll x, ll n){
  
  if (n==0){
    return 1;
  }
  
  else if (n==1){
    return x%MOD;
  }
  else if (n%2==0){
    return (factorial(x,n/2)*factorial(x,n/2))%MOD;
  }
  
  else {
    return (((factorial(x,(n-1)/2)*factorial(x,(n-1)/2))%MOD)*x)%MOD;
  }

}
  



int main(){
  

  int n,k;
  cin>>n>>k;
  
  vector<ll> com1(n-k+2);
  vector<ll> com2(k);
  
  com1.at(0)=1;
  com2.at(0)=1;
  
  for (int i=1;i<=n-k+1;i++){
    com1.at(i)=(((com1.at(i-1)*(n-k-i+2))%MOD)*factorial(i,MOD-2))%MOD;
  }
  
  for (int i=1;i<=k-1;i++){
    com2.at(i)=(((com2.at(i-1)*(k-i))%MOD)*factorial(i,MOD-2))%MOD;
  }
  
  for (int i=1;i<=k;i++){
    if (i<=n-k+1){
      cout<<(com1.at(i)*com2.at(i-1))%MOD<<endl;
    }
    else {
      cout<<0<<endl;
    }
  }
  


}










