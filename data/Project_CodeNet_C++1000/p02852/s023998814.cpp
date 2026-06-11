// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,m,b_idx;
  string s;
  vector<ll> ans;
  cin >> n >> m >> s;
  for(int i=n;i>0;){
    b_idx = -1;
    for(int j=1;j<=m&&i-j>=0;j++){
      if(s[i-j]=='0') b_idx = i-j;
    }
    if(b_idx==-1){
      cout << -1<<endl;
      return 0;
    }
    ans.push_back(i-b_idx);
    i = b_idx;
  }
  reverse(ans.begin(),ans.end());
  for(auto i:ans){
    cout <<i<<" ";
  }
  cout << endl;
}
