#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  deque<char> ds(s.size());
  for (int i = 0; i < s.size(); ++i) ds[i] = s[i];
  
  int q; cin >> q;
  int rev = 0;
  for (int i = 0; i < q; ++i){
    int type; cin >> type;
    if (type == 2){
      int f; char c;
      cin >> f >> c; --f;
      if (rev) f = 1 - f;
      if (f == 0) ds.push_front(c);
      else ds.push_back(c);
    }
    else rev =1 - rev;
  }
  if (rev) reverse(ds.begin(), ds.end());
  for (auto c:ds) cout << c;
  cout << endl;
}
