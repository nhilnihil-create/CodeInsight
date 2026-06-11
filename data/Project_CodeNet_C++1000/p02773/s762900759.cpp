#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
  int n;
  vector<string> sub;
  map<string, int> s;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    sub.push_back(tmp);

    auto itr = s.find(tmp);
    if(itr != s.end()) {
      itr->second += 1;
    } else {
      s.insert(make_pair(tmp, 1));
    }
  }

  sort(sub.begin(), sub.end());
  sub.erase(unique(sub.begin(), sub.end()), sub.end());

  int max_str = 0;
  for(string x : sub) {
    auto itr = s.find(x);
    int s_cnt = itr->second;
    max_str = max(max_str, s_cnt);
  }

  for(string x : sub) {
    auto itr = s.find(x);
    int s_cnt = itr->second;
    if(max_str == s_cnt) cout << x << endl;
  }
  return 0;
}
