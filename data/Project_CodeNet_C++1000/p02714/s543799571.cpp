#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+5;
typedef long long ll;

int main() {
  ll N;
  cin>>N;
  string s;
  cin>>s;
  ll r=0,g=0,b=0;
  for(int i=0;i<N;i++){
    if(s[i]=='R'){
      r++;
    }
    else if(s[i]=='G'){
      g++;
    }
    else{
      b++;
    }
  }
  ll ans=r*g*b;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(s[i]==s[j]){
        continue;
      }
      ll k=2*j-i;
      if(k>=N) continue;
      else if(s[j]!=s[k]&&s[k]!=s[i]){
        ans--;
      }
      
    }
  }
  cout<<ans<<endl;
        
}
