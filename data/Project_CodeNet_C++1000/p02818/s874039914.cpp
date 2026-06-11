#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(a+b<=c) cout<<0<<" "<<0;
  else if(a<=c) cout<<0<<" "<<(a+b)-c;
  else cout<<a-c<<" "<<b;
  return 0;
}
