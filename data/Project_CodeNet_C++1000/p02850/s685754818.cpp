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

struct edge{
  int to,cost;
};

int main()
{
  int N;
  cin >> N;
  vector<P> A(N-1);
  vector<vector<edge>> vec(N,vector<edge>());
  REP(i,N-1){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    edge e = {A[i].second,i};
    vec.at(A[i].first).push_back(e);
    edge e2 = {A[i].first,i};
    vec.at(A[i].second).push_back(e2);
  }

  vector<int> ans(N-1,0);
  REP(i,N){
    int y=0;
    for(auto x:vec.at(i)){
      if(ans.at(x.cost)!=0){
        y=ans.at(x.cost);
      }
    }
    int cnt=1;
    for(auto x:vec.at(i)){
      if(cnt==y){
        cnt++;
      }
      if(ans.at(x.cost)==0){
        ans.at(x.cost)=cnt;
        cnt++;
      }
    }
  }
  
  int MAX = 0;
  REP(i,N-1){
    MAX = max(MAX,ans.at(i));
  }

  cout << MAX << endl;
  REP(i,N-1){
    cout << ans.at(i) << endl;
  }
}