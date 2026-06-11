#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  ll c=100;
  for(ll i=0;c<a;i++){
    c=c/100+c;
    b+=1;
  }
  cout<<b<<endl;
  
}