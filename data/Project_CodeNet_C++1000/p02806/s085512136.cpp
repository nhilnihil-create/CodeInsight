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
signed main(){
  int N,sum=0; cin>>N;
  vector<pair<string,int>> S(N);
  rep(i,0,N){
    cin>>S[i].first>>S[i].second;
    sum+=S[i].second;
    }
  int ans=0;
  string X; cin>>X;
  rep(i,0,N){
    ans+=S[i].second;
    if(S[i].first==X)
      break;
    }
  cout<<sum-ans<<endl;
  }
