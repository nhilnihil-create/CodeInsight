#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long a,b; cin>>a>>b;
  cout<<a*b/gcd(a,b);
  return 0;
}