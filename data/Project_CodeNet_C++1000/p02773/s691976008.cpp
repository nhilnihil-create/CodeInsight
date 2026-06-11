#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  map<string, int> mp;
  int cnt = 0;
  set<string> S;
  rep(i,n){
    string s;
    cin >> s;
    S.insert(s);
    mp[s] ++;
    cnt = max(cnt, mp[s]);
  }
  for(auto v : S){
    if(mp[v] == cnt) cout << v << endl;
  }
}
