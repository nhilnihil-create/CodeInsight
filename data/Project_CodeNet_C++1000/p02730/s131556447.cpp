#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t,u; cin>>s,t=s.substr(0,(s.size()-1)/2),u=s.substr((s.size()+1)/2);
  cout<<(t==u?"Yes":"No");
}