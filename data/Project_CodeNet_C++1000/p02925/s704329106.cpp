#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N; cin>>N;
  vector<vector<vector<pii>>> A(N,vector<vector<pii>>(N));
  vii C(N,vi(N));
  rep(i,0,N){
    vi B(N-1);
    rep(j,0,N-1) cin>>B[j];
    rep(j,1,N-1){
      int P=i,Q=B[j]-1,R=B[j-1]-1,S=i;
      if(P>Q) swap(P,Q);
      if(S>R) swap(S,R);
      A[S][R].pb(mp(P,Q));
      C[P][Q]++;
    }
  }
  stack<pii> Q;
  rep(i,0,N){
    rep(j,i+1,N){
      if(C[i][j]==0) Q.push(mp(i,j));
    }
  }
  vector<pii> D;
  while(Q.size()>0){
    int X=Q.top().first,Y=Q.top().second;
    Q.pop();
    D.pb(mp(X,Y));
    rep(i,0,A[X][Y].size()){
      int P=A[X][Y][i].first,R=A[X][Y][i].second;
      C[P][R]--;
      if(C[P][R]==0) Q.push(mp(P,R));
    }
  }
  if(D.size()==N*(N-1)/2){
    vii dp(N,vi(N,1));
    rep(i,0,D.size()){
      int X=D[i].first,Y=D[i].second;
      rep(j,0,A[X][Y].size()){
        int P=A[X][Y][j].first,R=A[X][Y][j].second;
        dp[P][R]=max(dp[P][R],dp[X][Y]+1);
        }
      }
    int ans=0;
    rep(i,0,N){
      rep(j,0,N) ans=max(ans,dp[i][j]);
      }
    cout<<ans<<endl;
  }
  else cout<<-1<<endl;
  }

