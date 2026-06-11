#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  vector<ll>vec(3);
  ll d=min(a,b+c);
  cout<<c-d+b<<endl;
  return 0;
}