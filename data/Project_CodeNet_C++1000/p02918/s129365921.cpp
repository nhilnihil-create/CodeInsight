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
  int N,K;
  string S;
  cin >> N >> K >> S;
  
  int count=0;
  if(N>1) {
    if(S[0]=='R'&&S[1]=='R') count++;
    if(S[N-1]=='L'&&S[N-2]=='L') count++;
    rep2(i,1,N-1) {
      if(S[i]=='L'&&S[i-1]=='L'||S[i]=='R'&&S[i+1]=='R') count++;
    }
  }
  
  cout << min(N-1,count+K*2) << endl;
}