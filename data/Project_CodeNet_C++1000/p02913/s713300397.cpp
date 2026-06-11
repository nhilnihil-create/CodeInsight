#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  int l=0,r=N;
  while(r-l>1) {
    int m=(l+r)/2;
    bool flag=false;
    vector<string> s;
    rep(i,N-m+1) s.push_back(S.substr(i,m));
    rep(i,N-m*2+1) {
      rep2(j,i+m,N-m+1) flag|=s[i]==s[j];
    }
    if(flag) l=m;
    else r=m;
  }
  
  cout << l << endl;
}