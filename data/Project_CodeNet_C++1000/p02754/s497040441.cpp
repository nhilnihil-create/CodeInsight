#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,a,b,ans;
  cin>>n>>a>>b;
  ans=0;
  if(n%(a+b)>a){
    ans=(n/(a+b)*a)+a;
  }else{
    ans=(n/(a+b)*a)+n%(a+b);
  }
  cout<<ans;
}