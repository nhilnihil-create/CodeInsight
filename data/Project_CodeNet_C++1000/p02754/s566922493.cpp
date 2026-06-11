#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  long long cycle = a+b;
  long long ret = (n/cycle)*a;
  n%=cycle;
  if(n<a) ret+=n;
  else ret+=a;
  cout<<ret;
}
  