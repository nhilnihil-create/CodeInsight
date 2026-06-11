#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
using ll = long long;
int main(){
  ll K;
  ll res=0;
  cin >> K;
  for(ll i=1;i<K+1;i++){
    for(ll j=1;j<K+1;j++){
      for(ll k=1;k<K+1;k++){
      res+=gcd(gcd(i,j),k);
      }
    }
  }
	cout << res << endl;
}