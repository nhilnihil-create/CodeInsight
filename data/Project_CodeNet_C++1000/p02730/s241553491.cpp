#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  
  string sub_s = s;
  reverse(sub_s.begin(), sub_s.end());
  int l = s.size();
  string a = s.substr(0, (l-1)/2);
  string sub_a = a;
  reverse(sub_a.begin(), sub_a.end());
  string b = s.substr((l+1)/2, l);
  string sub_b = b;
  reverse(sub_b.begin(), sub_b.end());
  
  bool ok = true;
  if(s != sub_s) ok = false;
  if(a != sub_a) ok = false;
  if(b != sub_b) ok = false;
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
