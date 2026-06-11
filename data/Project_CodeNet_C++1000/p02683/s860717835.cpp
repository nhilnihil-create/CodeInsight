#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,M,X,ans=-1,p=0,t=1;
  cin >> N >> M >> X;
  int C[N],A[N][M],P[M]={};
  for (int i = 0; i < N; i++)
  {
    cin >> C[i];
    for (int j = 0; j < M; j++)
    {
      cin >> A[i][j];
    }
    
  }
  for (int bit = 0; bit < (1 << N); ++bit)
  {
    for (int i = 0; i < N; i++)
    {
      if ((bit >> i) & 1)
      {
        p+=C[i];
        for (int j = 0; j < M; j++)
        {
          P[j]+=A[i][j];
        }
        
      }
      
    }
    for (int j = 0; j < M; j++)
    {
      if (P[j] < X)
        t = 0;
    }
    if(ans == -1 && t==1) ans=p;
    else if (t == 1 && ans > p)ans = p;

    p=0;
    t=1;
    for (int i = 0; i < M; i++)
    {
      P[i]=0;
    }
    
  }
  cout << ans;
}
