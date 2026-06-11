#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,a,b,c,sum,p;
  cin>>n>>a>>b;
  c=a+b;
  sum=(n/c)*a;
  p=n%c;
  if(p<=a)sum=sum+p;
  else if(p>a)sum=sum+a;
  cout<<sum<<endl;
  
  return 0;
  
}
