#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int D;
  cin>>D;
  vector<int> c(26+1);
  for(int i(1);i<27;i++){
    cin>>c[i];
  }
  vector<vector<int>> s(D+1,vector<int>(26+1));
  for(int i(1);i<=D;i++){
    for(int j(1);j<=26;j++){
      cin>>s[i][j];
    }
  }
  vector<int> t(D+1);
  for(int i(1);i<=D;i++){
    cin>>t[i];
  }
  int nowp(0);
  vector<int> l(D,0);
  for(int i(1);i<=D;i++){
    nowp += s[i][t[i]];
    l[t[i]] = i;
    for(int j(1);j<=26;j++){
      nowp -= c[j]*(i-l[j]);
    }
    cout << nowp << endl;
  }
  return 0;
}

