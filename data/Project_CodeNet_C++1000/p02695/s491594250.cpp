#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


int N, M, Q;
ll MAX=0;

void dfs(ll min,ll Max,int x,vector<vector<ll>> q,vector<ll> &A){
  if(x==N-1){
    FOR(i,min,Max+1){
      A[x]=i;
      ll cnt = 0;
      REP(j,Q){
        if(A.at(q.at(j).at(1))-A.at(q.at(j).at(0))==q.at(j).at(2)){
          cnt+=q.at(j).at(3);
        }
      }
      MAX = max(MAX,cnt);
    }
  }else{
    FOR(i,min,Max+1){
      A[x]=i;
      dfs(i,Max,x+1,q,A);
    }
  }
}

int main()
{
  cin >> N >> M >> Q;
  vector<vector<ll>> q(Q,vector<ll>(4));
  vector<ll> A(N);
  
  REP(i, Q){
    REP(j, 4){
      cin >> q.at(i).at(j);
    }
    q.at(i).at(0)--;
    q.at(i).at(1)--;
  }
  
  dfs(1,M,0,q,A);
  cout << MAX << endl;
}