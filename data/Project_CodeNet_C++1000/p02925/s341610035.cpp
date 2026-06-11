#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int N;
int A[1010][1010];
int nex[1010];


int main(){
  cin>>N;
  rep(i,N) rep(j,N-1){
    cin>>A[i][j];
    A[i][j]--;
  }
  
  int ans=0,fin=0;
  int par[N]; rep(i,N) par[i]=-1;
  queue<int> que; rep(i,N) que.push(i);
  while(fin<N){
    int siz=que.size();
    if(siz==0){
      cout<<-1<<endl;
      return 0;
    }
    while(siz--){
      int i=que.front(); que.pop();
      par[i]=A[i][nex[i]];
      int j=par[i];
      if(i==par[j]){
        nex[i]++,nex[j]++;
        if(nex[i]==N-1) fin++;
        else que.push(i);
        if(nex[j]==N-1) fin++;
        else que.push(j);
      }
    }
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}