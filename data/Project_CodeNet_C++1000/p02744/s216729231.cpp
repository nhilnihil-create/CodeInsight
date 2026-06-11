#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int N;
string henkan(string s) {
  map<char, int> chars;
  map<char, char> char2char;
  string res = "";
  for (int i=0; i<(int)s.size(); i++) {
    if (chars[s[i]]==0) {
      char bck = char('a'+chars.size()-1);
      res.push_back(bck);
      chars[s[i]]++;
      char2char[s[i]] = bck;
    }
    else res.push_back(char2char[s[i]]);
  }
  return res;
}

map<string, int> maps;
set<string> ans;
void dfs(string s) {
  string x = henkan(s);
  if (maps[x]) return;
  maps[x]++;
  if ((int)x.size()==N) {
    ans.insert(x);
    return;
  }
  for (int i=0; i<N; i++) {
    string nx = x;
    nx.push_back(char(i+'a'));
    dfs(nx);
  }
}

int main() {
  cin.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  cin >> N;
  dfs("");
  for(auto y: ans) cout << y << endl;
  return 0;
}