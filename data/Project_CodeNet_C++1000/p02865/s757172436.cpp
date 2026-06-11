#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

int main(void)
{
  int N;
  cin >> N;
  int ret;
  if(N%2==0)
  {
    ret=N/2-1;
  }
  else
  {
    ret=N/2;
  }
  
  cout << ret;
  return 0;
}