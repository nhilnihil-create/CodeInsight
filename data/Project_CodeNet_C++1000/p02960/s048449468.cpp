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
  
  ll ten=1;
  int r=0;
  vi question;
  for(int i=S.size()-1;i>=0;i--) {
    if(S[i]=='?') question.push_back(ten);
    else r=(r+ten*(S[i]-'0'))%13;
    ten=ten*10%13;
  }
  
  int size=question.size();
  vvl rem(size+1,vl(13));
  rem[0][r]=1;
  rep(i,size) {
    rep(j,13) {
      rep(k,10) {
        rem[i+1][(j+question[i]*k)%13]+=rem[i][j];
        rem[i+1][(j+question[i]*k)%13]%=INF;
      }
    }
  }
  
  cout << rem[size][5] << endl;
}