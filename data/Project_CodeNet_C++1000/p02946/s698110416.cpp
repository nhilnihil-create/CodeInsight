#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int k, x;
  cin >> k >> x;
  for(int i = x - k + 1; i <= x + k - 1; i++)
  {
    cout << i << ((i == x+k-1)? "\n" : " ");
  }
  
  return 0;
}