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
  vi A(N);
  int sum=0;
  rep(i,0,N){
    cin>>A[i];
    sum+=A[i];
  }
  set<int> S;
  REP(i,1,sqrt(sum)){
    if(sum%i==0){
      S.insert(i);
      S.insert(sum/i);
    }
  }
  int ans=1;
  for(auto p:S){
    vi B(N);
    int me=0;
    rep(i,0,N){
      B[i]=A[i]%p;
      me+=B[i];
    }
    sort(ALL(B),greater<int>());
    int mem=0;
    rep(i,0,me/p) mem+=B[i];
    if(me-mem<=K) ans=p;
  }
  cout<<ans<<endl;
  }


