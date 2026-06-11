#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  
 ll N,M;
  cin>>N>>M;
  for(ll i=0;i<M;i++) {
ll A;
    cin>>A;
    N-=A;
  }
  if(N<0) {
cout<<-1<<endl;
  }
  else {
cout<<N<<endl;
  }
}
