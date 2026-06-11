#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll s=inf;

  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      s=min(s,n/i+i-2);
    }
  }
  cout << s << endl;

}