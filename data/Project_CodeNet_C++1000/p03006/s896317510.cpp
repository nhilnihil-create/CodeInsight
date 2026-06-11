#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
  int n; cin >> n;
  vector<pair<int,int>> xy(n);
  for(int i=0;i<n;i++) cin >> xy.at(i).first >> xy.at(i).second;
  map<pair<int,int>,int> mp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      int dx = xy.at(j).first-xy.at(i).first;
      int dy = xy.at(j).second-xy.at(i).second;
      if(!mp.count(make_pair(dx,dy))){
        mp[make_pair(dx,dy)] = 1;
      }else{
        mp.at(make_pair(dx,dy))++;
      }
    }
  }
  int m = 0;
  for(auto a:mp){
    m = max(m,a.second);
  }
  cout << n-m;
}