#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long int lli;
int main()
{
  lli i,j,n,t,cnt = 0;
  cin >> n;
  for(i=0;i<n;i++)
  {
    cin >> j;
    if(i % 2 == 0 && j % 2 == 1)
      cnt++;
  }
  cout << cnt;
  
  
  return 0;
}
