#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  vector<int> H(N);
  for(int i=0;i<N;i++)scanf("%d ",&H[i]);
  int ans=0,count=0;
  for(int i=1;i<N;i++)
  {
    if(H[i-1]>=H[i]){count++;ans=max(ans,count);}
    else count=0;
  }
  printf("%d\n",ans);
}