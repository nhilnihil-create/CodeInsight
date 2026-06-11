#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 1001; //N+1
int V_MAX = 20001; //W+1
int INF=1e9;
typedef pair<int,int> P;
int main()
{
  int n,v,i,j;
  int w[N_MAX][V_MAX];
  P ww[N_MAX]; //(v,w)
  cin >> v >> n;
  for(i=1;i<=n;i++)
    cin >> ww[i].first >> ww[i].second;
  w[0][0]=0;
  fill(w[0]+1,w[0]+V_MAX,INF);
  for(i=1;i<=n;i++)
    for(j=0;j<V_MAX;j++)
      if(j<ww[i].first){
        w[i][j]=w[i-1][j];
      }else{
        w[i][j]=min(w[i-1][j],w[i][j-ww[i].first]+ww[i].second);
      }
  cout << *min_element(w[n]+v,w[n]+V_MAX) << endl;
  return 0;
}