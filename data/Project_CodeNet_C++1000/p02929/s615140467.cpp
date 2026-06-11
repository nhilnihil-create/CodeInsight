#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<vector<int>> lr(2);
  for(int i=0;i<2*n;i++){
    if((s[i]=='B') ^ (i%2)){
      lr[0].push_back(i);
    }
    else{
      lr[1].push_back(i);
    }
  }
  if(lr[0].size()!=lr[1].size()) cout << 0 << endl;
  else{
    ll ans=1;
    reverse(lr[0].begin(),lr[0].end());
    for(int i=0;i<n;i++){
      ans*=(lr[1].end()-lower_bound(lr[1].begin(),lr[1].end(),lr[0][i]))-i;
      ans%=MOD;
      ans*=(i+1);
      ans%=MOD;
    }
    cout << ans << endl;
  }
}