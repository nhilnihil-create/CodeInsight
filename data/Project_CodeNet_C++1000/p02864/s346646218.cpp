#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
using namespace std;
#define i64  long long
 #define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define MOD 1000000007



void solve()
{
  int N,K;
  cin>>N>>K;
  vector<int> data(N+1,0);
  for (int i = 0; i < N; i++)
  {
    cin>>data[i+1];
  }

  vector<vector<int> > DP(N+1,vector<int>(N+1,I64_MAX/4));
  DP[0][0] = 0;
  for (int i = 0; i < N+1; i++)
  {
    DP[i][0] = 0;
  }
  
    for(int i=1;i<=N;++i){
        DP[i][1]=data[i];
    }



  for (int i = 1; i <= N; i++)
  {
    for (int j = 2; j <= N; j++)
    {
      for (int x = 1; x < i; x++)
      {
        DP[i][j] = min(DP[i][j],DP[x][j-1] + max((int)0,data[i]-data[x]));
        // cout<<min(DP[i][j],DP[x][j-1] + max((int)0,data[i]-data[x]))<<endl;
      }
      
    }
    
  }
  //   for (int y = 0; y <= N - K; y++)
  // {
  //   /* code */
  //   for (int x = 0; x <= N; x++)
  //   {
  //     cout<<DP[y][x]<<" ";
  //   }
  //   cout<<endl;
  // }


  int ANS = I64_MAX;
  for (int i = 0; i <=N; i++)
  {
    ANS = min(ANS,DP[i][N-K]);
  }
  
  cout<<ANS<<endl;
  
  
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
 
  return 0;
}