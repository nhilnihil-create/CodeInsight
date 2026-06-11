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
  vi A(N);
  rep(i,0,N) cin>>A[i];
  map<int,int> M;
  rep(i,0,N) M[A[i]]++;
  vi B;
  for(auto p:M) B.pb(p.second);
  sort(ALL(B));
  int O=B.size();
  B.pb(INF);
  vi C(O+2);
  REP(i,0,O) C[i+1]=C[i]+B[i];
  int sum=C[O];
  REP(i,1,N){
    int left=0,right=N/i;
    while(left+1<right){
      int mid=(left+right)/2;
      int X=disup(B,mid);
      int Y=sum-C[X]-(O-X)*mid;
      if(mid*i+Y<=N) left=mid;
      else right=mid;
    }
    int ans=left;
    int X=disup(B,right);
    int Y=sum-C[X]-(O-X)*right;
    if(right*i+Y<=N) ans=right;
    cout<<ans<<endl;
  }
  }

