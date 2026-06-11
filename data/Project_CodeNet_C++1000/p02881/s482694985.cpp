#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  ll n;
  cin >> n;
  ll a=1;
  for(ll i=1;i<=pow(n,0.5);i++){
    if(n%i==0){
      a=i;
    }
  }
  ll b=n/a;
  cout << a+b-2 << endl;
}