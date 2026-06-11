#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  sort(all(A));
  vector<ll> note(A.back());
  
  for(ll i=0;i<N;i++) {
ll count=1;
    while(A[i]*count<=A.back()) {
note[A[i]*count-1]++;
    count++;
    }
  }
  
  ll ans=0;
  for(ll i=0;i<N;i++) {
if(note[A[i]-1]==1) {
ans++;
}
  }
  
  cout<<ans<<endl;
}