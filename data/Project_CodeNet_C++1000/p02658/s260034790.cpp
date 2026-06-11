#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll ten(ll x) {
  ll count=0;
while(x/10>0) {
x/=10;
  count++;
}
  return count;
}

int main() {
  ll N;
  cin>>N;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  
  sort(all(vec));
  if(vec[0]==0) {
cout<<0<<endl;
    return 0;
  }
  ll ans=1;
  for(ll i=0;i<N;i++) {
if(ten(ans)+ten(vec[i])>=18&&ans*vec[i]!=1000000000000000000) {
cout<<-1<<endl;
  return 0;
}
   else {
ans*=vec[i];
   }
  }
  
  if(ans>1000000000000000000) {
    cout<<-1<<endl;
  }
  else{

  
  cout<<ans<<endl;
}
}
  
  
  
