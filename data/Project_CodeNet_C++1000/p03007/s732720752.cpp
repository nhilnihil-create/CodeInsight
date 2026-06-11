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
  vi C(N);
  rep(i,0,N) cin>>C[i];
  sort(ALL(C));
  vi A(N-1),B(N-1);
  int j=0;
  rep(i,1,N-1){
    if(C[i]>0) break;
    A[j]=C[N-1];
    B[j++]=C[i];
    C[N-1]-=C[i];
  }
  rep(i,1,N-1){
    if(C[i]>0){
      A[j]=C[0];
      B[j++]=C[i];
      C[0]-=C[i];
    }
  }
  A[N-2]=C[N-1];
  B[N-2]=C[0];
  cout<<C[N-1]-C[0]<<endl;
  rep(i,0,N-1) cout<<A[i]<<" "<<B[i]<<endl;
  }
