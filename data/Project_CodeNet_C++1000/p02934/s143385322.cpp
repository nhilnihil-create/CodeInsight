#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  double b=0;
  for(ll i=0;i<a;i++){
    double c;
    cin>>c;
    b+=1/c;
  }
  cout<<fixed<<setprecision(6);
  cout<<1/b<<endl;
  return 0;
}
  
    
  