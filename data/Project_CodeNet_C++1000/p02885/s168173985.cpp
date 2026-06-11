#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;

  if(a-2*b <=0 ){
    cout << 0;
  }
  else
  {
    cout << a - 2 * b;
  }

}
