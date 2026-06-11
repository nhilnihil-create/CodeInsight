#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){

  if(b==0){
    return a;
  }
  return gcd(b , a%b);
}

ll gcdd(ll a, ll b , ll c){

  return gcd(gcd(a,b),c);
}


int main() {

 int n;
 cin>>n;
 ll sum = 0;

  for(int i =1 ;i<=n;i++){
    for(int j= 1;j<=n;j++){
      for(int k =1 ;k<=n;k++){
        sum += gcdd(i,j,k);
      }
    }
  }


  cout<<sum<<"\n";

  
  return 0;
}
