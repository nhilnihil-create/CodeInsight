#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll X;
  cin>>X;
  ll a=100;
  ll count=0;
  while(a<X) {
    a+=a/100;
    count++;
  }
  
  cout<<count<<endl;
}

