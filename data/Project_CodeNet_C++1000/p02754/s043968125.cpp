#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,A,B;
  cin>>N>>A>>B;
  ll a=N/(A+B);
  ll b=N%(A+B);
  if(b<A) {
    cout<<A*a+b<<endl;
    
  }
  else {
cout<<a*A+A<<endl;
  }
}
