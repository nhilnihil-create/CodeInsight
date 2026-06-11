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
  string S;
  cin >> S;
  int N=S.size();
  
  bool flag=!(N%2);
  if(flag) {
    rep(i,N/2) flag&=S[2*i]=='h'&&S[2*i+1]=='i';
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}