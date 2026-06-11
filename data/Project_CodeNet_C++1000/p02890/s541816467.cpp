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
//  #define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define MOD 1000000007


int fn(int X,vector<int> & D,vector<int> &kD)
{
  if(X == 0) return I64_MAX;
  return (kD[X] + X*(D[D.size()-1] - D[X]))/X;
}

void solve()
{
  int N;
  cin>>N;
  vector<int> vec(N+1,0);
  vector<int> D(N+1,0);
  vector<int> kD(N+1,0);
  vector<int> X_1(N+1,0);

  for (int i = 0; i < N; i++)
  {
    int A;
    cin>>A;
    // scanf("%d",&A);
    vec[A]++;
  }


  for (int i = 0; i < N+1; i++)
  {
    D[vec[i]]++;
  }


  for (int i = 0; i <= N; i++)
  {
    kD[i] = i *D[i];
  }

  for (int i = 0; i <= N-1; i++)
  {
    D[i+1] += D[i];
    kD[i+1] += kD[i];
  }

  for (int i = 1; i < N+1; i++)
  {
    X_1[i] = (kD[i] + i*(D[N] - D[i]))/i;
  }
  int X = N;
  for (int k = 1; k <= N; k++)
  {

    int ANS;
    while(X&&(k > X_1[X]))X--;
    ANS = X;
    cout<<ANS<<endl;
  }
  
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solve();
 
  return 0;
}