#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a;
  b=0;
  for(ll i=1;i<=a;i++){
    if(i%3!=0&&i%5!=0){
      b+=i;
    }
  }
  cout<<b<<endl;
}
