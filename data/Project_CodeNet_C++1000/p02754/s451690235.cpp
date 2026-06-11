#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n,a,b,c; cin>>n>>a>>b,c=(n/(a+b))*a,n%=(a+b);
  if(n>a) n=a;
  cout<<c+n;
}