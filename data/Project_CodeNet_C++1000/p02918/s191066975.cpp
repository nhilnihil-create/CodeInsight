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

int main()
{
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;

  int flag = 0;
  if(S.at(0)=='R'){
    flag=1;
  }
  int cnt = 0;
  vector<int> vec;
  REP(i,N){
    if(flag==1&&S.at(i)=='R'){
      cnt++;
    }else if(flag==0&&S.at(i)=='L'){
      cnt++;
    }else if(flag==1&&S.at(i)=='L'){
      vec.push_back(cnt);
      cnt=1;
      flag=0;
    }else if(flag==0&&S.at(i)=='R'){
      vec.push_back(cnt);
      cnt=1;
      flag=1;
    }
  }
  vec.push_back(cnt);

  int ans = 0;
  REP(i,vec.size()){
    ans+=vec.at(i)-1;
  }
  
  cout << ans+min(2*K,(int)vec.size()-1) << endl;
}