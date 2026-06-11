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
  rep(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }
  int cntmax = 0;
  for(auto p : mp) cntmax = max(cntmax, p.second);
  for(auto p : mp){
    if(p.second == cntmax) cout << p.first << endl;
  }
}
