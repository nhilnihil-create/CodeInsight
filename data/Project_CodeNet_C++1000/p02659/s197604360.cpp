#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a;
  double b;
  cin>>a>>b;
  long long ans=0;
  ans=b*100+0.01;
  ans=(ans*a)/100;
  cout<<ans;
}