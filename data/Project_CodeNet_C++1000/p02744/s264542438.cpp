#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N;
vector<string> ans;
void DFS(string s,int a) {
  if (s.size() == N) {
    ans.push_back(s);
    return;
  } else {
    for (int i = 0; i < a + 1; i++) {
      char c = 'a' + i;
      s += c;
      if (i == a) {
        DFS(s,a+1);
      } else {
        DFS(s,a);
      }
      s.pop_back();
    }
  }
}  

int main() {
  cin >> N;
  DFS("a",1);
  sort(ans.begin(),ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl; 
  }
  return 0;
}