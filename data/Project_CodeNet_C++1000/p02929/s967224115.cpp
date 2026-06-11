#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<vector<int>> lr(2);
  for(int i=0;i<2*n;i++)lr[(s[i]=='W')^(i%2)].push_back(i);
  if(lr[0].size()!=lr[1].size()) cout << 0 << endl;
  else{
    ll ans=1;
    reverse(lr[0].begin(),lr[0].end());
    auto itr=lr[1].end();
    for(int i=0;i<n;i++){
      itr=lower_bound(lr[1].begin(),itr,lr[0][i]);
      ans*=(lr[1].end()-itr)-i;
      ans%=MOD;
      ans*=(i+1);
      ans%=MOD;
    }
    cout << ans << endl;
  }
}