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




ll factorial(int n){
  if (n==0){
    return 1;
  }
  if (n==1){
    return 2;
  }
  if (n%2==0){
    return (factorial(n/2)*factorial(n/2))%MOD;
  }
  if (n%2==1){
    return (((factorial(n/2)*factorial(n/2))%MOD)*2)%MOD;
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
  
  vector<ll> count0(61,0);
  vector<ll> count1(61,0);
  
  rep(i,n){
    bitset<61> x(data.at(i));
    rep(j,61){
      if (x.test(j)==1){
        count1.at(j)++;
      }
      else {
        count0.at(j)++;
      }
    }
  }

 
  ll answer=0;
  
  rep(i,61){
    ll tmp;
    tmp=((count0.at(i)*count1.at(i)%MOD)*factorial(i))%MOD;
    answer+=tmp;
    answer%=MOD;
  }
  
  cout<<answer<<endl;

  
}


















