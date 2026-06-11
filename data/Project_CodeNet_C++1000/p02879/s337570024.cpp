#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;

  if(a>=1 && a<10 && b>=1 && b<10)
    cout << a*b;
  else
  {
    cout << "-1";
  }

}
