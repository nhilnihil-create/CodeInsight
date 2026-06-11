#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  int k;
  string s;
  cin >> k >> s;
  if(s.size() > k)cout << s.substr(0,k) << "..." << endl;
  else cout << s << endl;
  return 0;
}
