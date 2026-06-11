#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin>>x;
  int lcm=__gcd(360,x);
  int t= 360*x;
  t/=lcm;
  cout<<t/x;
}
