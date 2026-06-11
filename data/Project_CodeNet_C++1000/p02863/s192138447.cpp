#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 3001; //N+1
int W_MAX = 3001; //W+1
typedef pair<int,int> P;
int main()
{
  int n,w,i,j;
  int v[N_MAX][W_MAX];
  P ww[N_MAX];
  cin >> n >> w;
  for(i=1;i<=n;i++)
    cin >> ww[i].first >> ww[i].second;
  sort(ww+1,ww+n+1,greater<P>());
  v[0][0]=0;
  fill(v[0]+1,v[0]+w+1,-1);
  for(i=1;i<=n;i++){
    v[i][0]=0;
    v[i][1]=max(ww[i].second,v[i-1][1]);
    for(j=2;j<=w;j++)
      if(j<=ww[i].first||v[i-1][j-ww[i].first]==-1){
        v[i][j]=v[i-1][j];
      }else{
        v[i][j]=max(v[i-1][j],v[i-1][j-ww[i].first]+ww[i].second);
      }
  }
  cout << *max_element(v[n],v[n]+w+1) << endl;
  return 0;
}