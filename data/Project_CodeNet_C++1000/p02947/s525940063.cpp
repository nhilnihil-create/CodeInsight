#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<string> vec(N);
  for(ll i=0;i<N;i++) {
string S;
    cin>>S;
    sort(all(S));
    vec[i]=S;
  }
  sort(all(vec));
  
  ll ans=0;
  for(ll i=0;i<N-1;i++) {
  if(vec[i]==vec[i+1]) {
ll count=1;
    for(ll j=i+1;j<N;j++) {
      if(vec[i]==vec[j]) {
count++;
      }
      else {
i=j-1;
        break;
      }
      if(j==N-1) {
        i=j-1;
      }
    }
    ans+=count*(count-1)/2;
  }
  }
  
  
  cout<<ans<<endl;
}



  
    
    
    
