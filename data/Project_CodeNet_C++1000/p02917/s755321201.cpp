#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  vector<int> B(N);B[N-1]=100000;
  for(int i=0;i<N-1;i++)scanf("%d ",&B[i]);
  int ans=B[0];
  for(int i=1;i<N;i++)
  {
    int Ai=min(B[i],B[i-1]);
    ans+=Ai;//cout<<"I"<<i<<"Ai"<<Ai;
  }
  printf("%d\n",ans);
}