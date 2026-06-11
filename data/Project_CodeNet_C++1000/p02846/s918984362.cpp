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
  int A,B,C,D,E,F; cin>>A>>B>>C>>D>>E>>F;
  int P=A*(C-E),Q=B*(D-F);
  Q+=P;
  Q*=-1;
  if(P<0){
    P=-P;
    Q=-Q;
  }
  if(Q==0){
    cout<<"infinity"<<endl;
  }
  else if(Q>0){
    int ans=0;
    ans=P/Q*2+1;
    if(P%Q==0) ans--;
    cout<<ans<<endl;
  }
  else cout<<0<<endl;
  }
