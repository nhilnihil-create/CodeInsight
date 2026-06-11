#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ll long long
#define MOD 1000000007
#define MAX 100010
#define cout(v) REP(i,v.size()) cout << v[i] << " "; cout << endl;
using namespace std;
using Graph = vector<vector<int>>;
 
int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> r,g,b;
  REP(i,n){
    if(s[i] == 'R') r.push_back(i);
    else if(s[i] == 'G') g.push_back(i);
    else if(s[i] == 'B') b.push_back(i);
    else cout << "unti";
  }
  
  ll all = r.size()*g.size()*b.size();
  ll sub = 0;
  FOR(i,0,n){
    FOR(j,i+1,n){
      if(s[i] == s[j]) continue;
      int k = 2*j-i;
      if (k >= n || s[k] == s[i] || s[k] == s[j]) continue;
      sub++;
    }
  }
  cout << all - sub;
}