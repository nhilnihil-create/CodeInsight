#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll K,X;
  cin>>K>>X;
  ll x=X-(K-1);
  while(x<=X+(K-1)) {
cout<<" "<<x;
  x++;
  }
  cout<<endl;
}
 
