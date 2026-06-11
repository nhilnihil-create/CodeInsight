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
  int M=(N-1)*(N-2)/2;
  if(K<=M){
    cout<<N-1+M-K<<endl;
    REP(i,2,N) cout<<1<<" "<<i<<endl;
    int sum=0;
    rep(i,2,N){
      REP(j,i+1,N){
        if(sum==M-K) break;
        sum++;
        cout<<i<<" "<<j<<endl;
      }
    }
  }
  else cout<<-1<<endl;
  }
