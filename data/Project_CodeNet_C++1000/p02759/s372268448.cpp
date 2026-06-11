#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;

  if(n%2 == 0)
    cout << n / 2;
  else
  {
    cout << n / 2 + 1;
  }

}
