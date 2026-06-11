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
  int X=(1ll<<N);
  map<int,int> M;
  rep(i,0,X){
    int Y; cin>>Y;
    M[Y]++;
  }
  vi A(1);
  auto p=*M.rbegin();
  A[0]=p.first;
  M[A[0]]--;
  if(M[A[0]]==0) M.erase(A[0]);
  rep(i,0,N){
    int P=A.size();
    rep(j,0,P){
      auto itr=M.lower_bound(A[j]);
      if(itr==M.begin()){
        cout<<"No"<<endl;
        return 0;
      }
      itr--;
      auto p=*itr;
      int Y=p.first;
      A.pb(Y);
      M[Y]--;
      if(M[Y]==0) M.erase(Y);
    }
  }
  cout<<"Yes"<<endl;
  }

