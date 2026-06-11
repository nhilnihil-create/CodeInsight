#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
using P = pair<int,int>;
#define MOD 1000000007
/*
H=2*10^3,W=2*10^3なので、
最初に思いついた方法だと、
O(HW(H+W))になってしまって厳しい、、、
 
前処理をすることで計算量を減らせないか考える
*/

int main()
{
  int H,W;cin>>H>>W;
  char S[2020][2020];
  
  for (int i=1;i<=H;i++)
  {
    for (int j=1;j<=W;j++)
      cin>>S[i][j];
  }
  
  //DPみたいな感じで前処理をしておく
  //L[i][j]=i,jに明かりを置いた時に照らされるマスの総数
  int L[2020][2020];
  int R[2020][2020];
  int T[2020][2020];
  int D[2020][2020];
  
  for (int i=1;i<=H;i++)
  {
    for (int j=1;j<=W;j++)
    {
      if (S[i][j]=='#') L[i][j]=0;
      else 
      {
        if (j==1) L[i][j]=1;
		else L[i][j]=L[i][j-1]+1;
      }
    }
  }
  
  for (int i=1;i<=H;i++)
  {
    for (int j=W;j>=1;j--)
    {
      if (S[i][j]=='#') R[i][j]=0;
      else 
      {
        if (j==W) R[i][j]=1;
        else R[i][j]=R[i][j+1]+1; 
      }
    } 
  }
  
  for (int i=1;i<=H;i++)
  {
    for (int j=1;j<=W;j++)
    {
      if (S[i][j]=='#') T[i][j]=0;
      else 
      {
        if (i==1) T[i][j]=1;
		else T[i][j]=T[i-1][j]+1;
      }
    }
  }
  
  for (int i=H;i>=1;i--)
  {
    for (int j=1;j<=W;j++)
    {
      if (S[i][j]=='#') D[i][j]=0;
      else 
      {
        if (i==H) D[i][j]=1;
        else D[i][j]=D[i+1][j]+1; 
      }
    } 
  }
  /*
  for (int i=1;i<=H;i++)
  {
    for (int j=1;j<=W;j++)
    {
      cout<<"("<<i<<","<<j<<")=";
      cout<<T[i][j]<<" "<<D[i][j]<<endl;
    }
  }*/
  
  int mx=0;
  int light;
  for (int i=1;i<=H;i++)
  {
    for (int j=1;j<=W;j++)
    {
      light = L[i][j]+R[i][j]+T[i][j]+D[i][j];
      mx = max(mx,light);
    }
  }
  
  cout<<mx-3<<endl;
}