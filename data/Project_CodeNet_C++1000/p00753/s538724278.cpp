#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
  
using namespace std;
  
int f[300000];
  
int cast(int n)
{
  if(f[n] != -1)
  return f[n];

 
  for(int i = 2;i <= n/i;i++)
  {
    if(n / i == (double)(n) / (double)(i))
    {
       f[n] = 0;
       return 0;
    }
  }
 
  f[n] = 1;
  return 1;
}
  
  
  
int main()
{
  
  int n;
  memset(f,-1,300000 * sizeof(int));

  while(cin >> n && n)
  {
    int sum = 0;
    for(int i = n+1;i <= 2*n;i++)
    {
       sum += cast(i);
    }    
  
    cout << sum << endl;
  }
  
  
  return 0;
}