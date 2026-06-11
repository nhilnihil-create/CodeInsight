#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a;
  cin>>a;
  if(a%2==0) {
cout<<0.50000000<<endl;
  }
else {
  cout<<fixed<<setprecision(7);
cout<<(double)(a/2+1)/a<<endl;
}
}
