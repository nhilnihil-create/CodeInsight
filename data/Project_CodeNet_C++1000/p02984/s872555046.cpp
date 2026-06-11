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
  

  ll n;
  cin>>n;
  vector<ll> data(n);
  rep(i,n){
    ll tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  ll sum=0;
  rep(i,n){
    sum+=data.at(i);
  }
  
  vector<ll> answer(n);
  
  ll tmp=0;
  for (int i=1;i<=n-2;i+=2){
    tmp+=2*data.at(i);
  }
  answer.at(0)=sum-tmp;
  
  for (int i=1;i<n;i++){
    answer.at(i)=2*data.at(i-1)-answer.at(i-1);
  }
  
  rep(i,n-1){
    cout<<answer.at(i)<<" ";
  }
  cout<<answer.at(n-1)<<endl;
  
    
  


}










