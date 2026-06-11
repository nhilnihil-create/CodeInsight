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
signed main(){
  int N; cin>>N;
  vector<pii> A(N);
  rep(i,0,N) cin>>A[i].first>>A[i].second;
  vi X(N),Y(N);
  sort(ALL(A));
  rep(i,0,N){
    X[i]=A[i].first;
    Y[i]=A[i].second;
  }
  int ans=0;
  rep(i,0,N-1){
    rep(j,i+1,N){
      int P=X[j]-X[i],Q=Y[j]-Y[i];
      int count=0;
      rep(k,0,N-1){
        rep(l,i+1,N){
          if(X[l]-X[k]==P&&Y[l]-Y[k]==Q)
            count++;
        }
      }
      ans=max(ans,count);
    }
  }
  cout<<N-ans<<endl;
  }

