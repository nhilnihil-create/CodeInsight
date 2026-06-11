#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,D;
  cin>>N>>D;
  ll kansi=0;
  ll ans=0;
  while(kansi<N) {
kansi+=2*D+1;
    ans++;
  }
  cout<<ans<<endl;
}
  
  
 