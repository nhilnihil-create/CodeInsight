#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int n;
cin >> n;
map<string,int> mp;
rep(i,n) {
  string a;
  cin >> a;
  if (mp.count(a)) mp[a]++;
  else mp[a] = 1;
}
vector<pair<int,string>> vec(mp.size());
int i = 0;
for (auto p : mp) {
  vec.at(i).first = p.second;
  vec.at(i).second = p.first;
  i++;
}
sort(vec.begin(),vec.end());
int maxi = vec.at(mp.size()-1).first;
rep(i,vec.size()) {
  if (vec.at(i).first == maxi) cout << vec.at(i).second << endl;
}
}

