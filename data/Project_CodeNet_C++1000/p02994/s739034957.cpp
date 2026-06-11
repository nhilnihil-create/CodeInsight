#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,L;
  cin>>N>>L;
ll t=0;
  for(ll i=0;i<N;i++) {
    t+=L+i;
  }
  
  if(L<0&&L+N-1<0) {
t-=L+N-1;
  }
  else if(L>0) {
t-=L;
  }
  
  cout<<t<<endl;
}
  
  
  
  
  