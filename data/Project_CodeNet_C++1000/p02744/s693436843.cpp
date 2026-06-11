#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int N;
vector<string> S;

void dfs(int n, string s) {
  if(s.size()==N-1) {
    rep(i,n+2) S.push_back(s+(char)('a'+i));
  }
  else {
    rep(i,n+1) dfs(n,s+(char)('a'+i));
    dfs(n+1,s+(char)('a'+n+1));
  }
}

int main() {
  cin >> N;
  
  dfs(-1,"");
  sort(S.begin(),S.end());
  
  rep(i,S.size()) {
    cout << S[i] << endl;
  }
}