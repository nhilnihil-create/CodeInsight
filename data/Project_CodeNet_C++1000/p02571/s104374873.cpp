#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  string t;
  vector<int> ans;
  int count=0;
  cin >> s >> t;
  for(int i=0;i<=s.size()-t.size();i++){
    count = 0;
    for(int j=0;j<t.size();j++){
      if(s.at(i+j)!=t.at(j)){
        count++;
      }
    }
    ans.push_back(count);
  }
  sort(ans.begin(), ans.end());
  cout << ans.at(0) << endl;
  return 0;
}
