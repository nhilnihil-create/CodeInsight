#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const ll INF = 1e18 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  string s, t;
  cin >> s >> t;
  set<char> se;
  map<char, vector<int>> mp;
  rep(i, s.size()){
    se.insert(s.at(i));
    mp[s.at(i)].push_back(i);
  }
  int S = se.size();
  rep(i, t.size()){
    se.insert(t.at(i));
    int k = se.size();
    if(k > S){
      cout << -1 <<endl;
      return 0;
    }
  }
  ll k = s.size();
  ll cnt = 0, pos = -1;
  for(int i = 0; i < t.size(); i++){
    auto itr = upper_bound(all(mp[t.at(i)]), pos);
    if(itr - mp[t.at(i)].begin() >= mp[t.at(i)].size()){
      cnt++;
      pos = mp[t.at(i)][0];
    }else{
      pos = *itr;
    }
  }
  cout << cnt * k + pos + 1 <<endl;
}