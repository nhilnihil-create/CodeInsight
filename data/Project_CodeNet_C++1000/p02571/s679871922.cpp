#include <iostream>

using namespace std;

int comput(string a, int i, string b){
  int ans = 0;
  for(int j = 0;j < b.size();j++){
    if(a[i + j] != b[j]){
      ans++;
    }
  }
  return ans;
}

int main() {

  int n, ans = 1000;
  string s, t;
  cin >> s >> t;
  for(int i = 0;i < s.size() - t.size() + 1;i++){
    ans = min(ans, comput(s, i, t));
  }
  cout << ans;
  return 0;
}
