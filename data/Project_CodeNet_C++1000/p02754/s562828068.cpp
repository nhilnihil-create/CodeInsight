#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long n,a,b;
  cin >> n >> a >> b;
  long long x=n/(a+b);
  long long ans=a*x;
  if((a+b)*x+a<=n){
    ans+=a;
  }
  else{
    ans+=(n-(a+b)*x);
  }
  cout << ans << endl;
}