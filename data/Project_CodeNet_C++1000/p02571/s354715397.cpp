#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define INF 1001;

int dis(string a, string b);

int main(void)
{
  string S,T,slocal;
  int ans = INF;
  cin >> S >> T;
  int N = S.size() - T.size() + 1;
  int tlen = T.size();

  int dislocal;
  for(int i = 0; i < N;i++)
  {
    slocal = S.substr(i,tlen);
    dislocal = dis(T,slocal);
    if(dislocal < ans) ans = dislocal;
  }
  cout << ans << endl;
  // cout << T << endl;

  return 0;
}

int dis(string a, string b)
{
  int N = a.size();
  int dis = 0;
  for(int i=0;i<N;i++)
  {
    if (a[i] != b[i]) dis++;
  }
  return dis;
}
