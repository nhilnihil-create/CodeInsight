#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

int main() {
  string s,t; cin>>s>>t;
  int cnt=0;
  rep(i,s.size()) {
    if(s[i]!=t[i]) cnt++;
  }
  cout<<cnt<<endl;
}
