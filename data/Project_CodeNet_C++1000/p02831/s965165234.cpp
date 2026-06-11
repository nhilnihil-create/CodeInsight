#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;
  cin>>a>>b;
  if(a<b) swap(a,b);
  long long sum=gcd(a,b);
  a=a/sum;
  b=b/sum;
  cout<<a*b*sum<<endl;
}
