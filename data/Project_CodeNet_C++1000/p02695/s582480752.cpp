#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int n,m,q,ans=0;

void dfs(int s, VI &A, VVI &info){
  if(A.size() == n){
    int cnt = 0;
    REP(i,0,q){
      if(A[info[i][1]] - A[info[i][0]] == info[i][2]){
        cnt += info[i][3];
      }
    }
    ans = max(ans,cnt);
    A.pop_back();
  }
  else{
    REP(i,s,m+1){
      A.push_back(i);
      dfs(i,A,info);
    }
    if(!A.empty()){A.pop_back();}
  }
}

int main(){
  cin >> n >> m >> q;
  VVI info(q, VI(4));
  REP(i,0,q){
    cin >> info[i][0] >> info[i][1] >> info[i][2] >> info[i][3];
    info[i][0]--;
    info[i][1]--;
  }
  
  VI A(0);
  
  dfs(1,A,info);
  
  cout << ans << endl;
  
  return 0;
}
