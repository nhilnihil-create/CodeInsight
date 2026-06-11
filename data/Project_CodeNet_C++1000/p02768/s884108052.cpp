#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back




ll factorial(ll i, ll n){
  if (n==0){
    return 1;
  }
  if (n==1){
    return i%MOD;
  }
  if (n%2==0){
    return (factorial(i,n/2)*factorial(i,n/2))%MOD;
  }
  if (n%2==1){
    return (((factorial(i,n/2)*factorial(i,n/2))%MOD)*i)%MOD;
  }
}



int main(){

  ll n,a,b;
  cin>>n>>a>>b;
  
  vector<ll> combi(b+1);
  combi.at(0)=1;
  
  for (int i=1;i<=b;i++){
    combi.at(i)=(((combi.at(i-1)*(n-i+1))%MOD)*factorial(i,MOD-2))%MOD;
  }
  
  ll answer;
  answer=factorial(2,n)-1-combi.at(a)-combi.at(b);
  
  while (answer<0){
    answer+=MOD;
  }
  
  cout<<answer<<endl;

  
}


















