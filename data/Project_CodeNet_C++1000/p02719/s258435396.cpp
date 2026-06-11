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


ll N,K;
cin>>N>>K;
ll ans=min(N%K, abs((N%K)-K));
    cout<<ans<<endl;

  
  return 0;
}
