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
  int N,K; cin>>N>>K;
  vii A(N);
  rep(i,0,N-1){
    int X,Y; cin>>X>>Y;
    A[X-1].pb(Y-1);
    A[Y-1].pb(X-1);
  }
  vector<bool> F(N,1);
  F[0]=0;
  queue<int> Q;
  Q.push(0);
  int ans=K;
  while(Q.size()>0){
    int X=Q.front();
    Q.pop();
    int count=1;
    rep(i,0,A[X].size()){
      int Y=A[X][i];
      if(F[Y]){
        F[Y]=0;
        Q.push(Y);
      }
      else
        count++;
    }
    int sum=A[X].size()+1;
    rep(i,0,sum-count){
      ans*=max(0ll,K-count-i);
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
  }

