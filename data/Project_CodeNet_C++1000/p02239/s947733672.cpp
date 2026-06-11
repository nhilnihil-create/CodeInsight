#include <iostream>
#include <queue>
using namespace std;
static const int N = 101;
void bfs(int);
int n,M[N][N],d[N],u,i,j;
string color[N];
int main(){
  int inu,k,v;
  cin >> n;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      M[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    cin >> inu >> k;
    for(j=0;j<k;j++){
      cin >> v;
      M[inu][v]=1;
    }
  }
  bfs(1);
  for(i=1;i<=n;i++){
    if(d[i]>1000000) cout << i << ' ' << -1 << endl;
    else cout << i << ' ' << d[i] << endl;
  }
  return 0;
}
void bfs(int s){
  queue<int> q;
  for(i=1;i<=n;i++){
    color[i]="WHITE";
    d[i]=1000000000;
  }
  color[s]="GLAY";
  d[s]=0;
  q.push(s);
  while(q.empty()!=true){
    u=q.front();
    q.pop();
    for(i=1;i<=n;i++){
      if(M[u][i]&&color[i]=="WHITE"){
	color[i]="GLAY";
	d[i]=d[u]+1;
	q.push(i);
      }
    }
    color[u]="BLACK";
  }
}