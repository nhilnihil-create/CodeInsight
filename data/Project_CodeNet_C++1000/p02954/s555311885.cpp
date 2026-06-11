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
  string S;
  cin >> S;

  int flag = 0;//0はR,1はL
  int x=0;
  int y,z=0;
  vector<int> ans(S.size(),0);
  REP(i,S.size()){
    if(S.at(i)=='L'&&flag==0){
      y=i;
      flag=1;
    }else if(S.at(i)=='R'&&flag==1){
      x=z;
      z=i;
      flag=0;
      ans.at(y-1)=(y-x+1)/2+(z-y)/2;
      ans.at(y)=(y-x)/2+(z-y+1)/2;
    }
  }
  x=z;
  z=S.size();
  ans.at(y-1)=(y-x+1)/2+(z-y)/2;
  ans.at(y)=(y-x)/2+(z-y+1)/2;

  REP(i,S.size()){
    cout << ans.at(i) << " ";
  }
  cout << endl;
}