#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; string s; cin>>n>>s;
  vector<char> v; for(char c:s) v.push_back(c);
  v.erase(unique(v.begin(),v.end()),v.end());
  cout<<v.size();
}