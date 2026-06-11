#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair

int main() {
  int k;
  string s;
  cin>>k>>s;
  if(s.size()<=k) cout<<s<<endl;
  else cout<<s.substr(0,k)<<"..."<<endl;
}
