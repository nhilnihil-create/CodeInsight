#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int h[1000005];
int day[1000005];

int main(){
  int n;
  cin>>n;
  vector<int> g[1000005];
  rep(i,n){
    int from;
    cin>>from; from--;
    rep(j,n-2){
      int to;
      cin>>to; to--;
      int a=i*n+from;
      if(i>from) a=from*n+i;
      int b=i*n+to;
      if(i>to) b=to*n+i;
      g[a].push_back(b);
      h[b]++;
      from=to;
    }
  }

  queue<int> q;
  rep(i,n*n) if(h[i]==0){
    q.push(i);
    day[i]=1;
  }
  while(q.size()){
    int p1=q.front(); q.pop();
    for(int p2:g[p1]){
      h[p2]--;
      if(h[p2]==0){
	day[p2]=day[p1]+1;
	q.push(p2);
      }
    }
  }
  int ans=0;
  rep(i,n*n){
    if(day[i]==0){
      cout<<-1<<endl;
      return 0;
    }
    ans=max(ans,day[i]);
  }
  cout<<ans<<endl;
  return 0;
}

