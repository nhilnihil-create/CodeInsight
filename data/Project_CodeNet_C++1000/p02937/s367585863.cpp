#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[100010];
  
int main()
{
  string s,t;
  cin >> s >> t;
  vector<vector<int>> vec(26,vector<int> (s.size(),-1));
  REP(i,26){
    int cnt = 0;
    int flag2 = 0;
    REPR(j,s.size()-1){
      if(s.at(j)==i+'a'){
        cnt=0;
        vec.at(i).at(j)=cnt;
        flag2=1;
      }else{
        cnt++;
        vec.at(i).at(j)=cnt;
      }
    }
    REPR(j,s.size()-1){
      if(flag2==0){
        vec.at(i).at(j)=-1;
      }else if(s.at(j)==i+'a'){
        break;
      }else{
        cnt++;
        vec.at(i).at(j)=cnt;
      }
    }
  }

  dp[0]=-1;
  int flag = 0;
  FOR(i,1,t.size()+1){
    if(vec.at(t.at(i-1)-'a').at(dp[i-1]%s.size())!=-1){
      dp[i]=dp[i-1]+1+vec.at(t.at(i-1)-'a').at((dp[i-1]+1)%s.size());
    }else{
      flag=1;
      break;
    }
  }

  if(flag==0){
    cout << dp[t.size()]+1 << endl;
  }else{
    cout << -1 << endl;
  }
}