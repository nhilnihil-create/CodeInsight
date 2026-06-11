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
  int N,ans=1; cin>>N;
  vi memo(3);
  rep(i,0,N){
    int X; cin>>X;
    int count=0;
    rep(j,0,3){
      if(memo[j]==X){
        if(count==0)
          memo[j]++;
        count++;
        }
      }
    ans*=count;
    ans%=MOD;
    }
  cout<<ans<<endl;
  }
