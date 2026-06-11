#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int,int>;
const ll mod = 1e9+7;

vector<int> primes((int)1e5+1000, 0);
void calc(){
  primes[0]=2,primes[1]=2,primes[2]=2;
  int current_max_prime = 2;
  for(ll i=2; i<(ll)1e5+1000; i++){
    if(primes[i]!=-1){
      for(int j=current_max_prime+1; j<=i; j++) primes[j]=i;
      current_max_prime = i;
      for(ll j=i*i; j<(ll)1e5+1000; j+=i) primes[j]=-1;
    }
  }

}

int main(){
  calc();
  int x;
  cin>>x;

  cout<<primes[x]<<endl;

  return 0;
}