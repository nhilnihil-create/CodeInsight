#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,K,count=0;
  cin >> N >> K;
  int d[K], A[K][N], ans[N]={};
  for (int i = 0; i < K; i++)
  {
    cin >> d[i];
    for (int j = 0; j < d[i]; j++)
    {
      cin >> A[i][j];
      ans[A[i][j]-1]++;
    }
    
  }
  for (int i = 0; i < N; i++)
  {
    if (ans[i]==0) count++;
    
  }
  cout << count;
    }
