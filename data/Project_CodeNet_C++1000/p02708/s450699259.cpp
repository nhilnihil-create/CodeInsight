#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
ll l=1000000007;

int main() {
  ll n,k; cin>>n >>k;
  ll a= 0;
  for(int i=k;i<=n+1; i++){
    a+=(n-i+1)*i+1;
    a%= l;
  }
  cout<<a<<endl;
}