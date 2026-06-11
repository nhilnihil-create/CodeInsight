#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll X,N;
  cin>>X>>N;
set<ll> S;
  for(ll i=0;i<N;i++) {
ll p;
    cin>>p;
    S.insert(p);
  }
  if(!S.count(X)) {
    cout<<X<<endl;
    return 0;
  }
  for(ll i=1;i<1000;i++) {
    if(!S.count(X-i)) {
      cout<<X-i<<endl;
      break;
    }
    else if(!S.count(X+i)) {
cout<<X+i<<endl;
      break;
    }
  }
cout<<endl;
}
