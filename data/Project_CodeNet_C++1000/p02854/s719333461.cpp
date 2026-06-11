#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum=sum+a.at(i);
  }
  ll sumh=sum/2;
  ll suma=0;
  for(int i=0;i<n;i++){
    suma=suma+a.at(i);
    if(suma==sumh){
      cout << 0 << endl;
      return 0;
    }
    if(suma>sumh){
      if((suma-sumh)<=(sumh-suma+a.at(i))){
        cout << 2*suma-sum << endl;
        return 0;
      }
      else{
        cout << sum-2*(suma-a.at(i)) << endl;
        return 0;
      }
    }
  }
}