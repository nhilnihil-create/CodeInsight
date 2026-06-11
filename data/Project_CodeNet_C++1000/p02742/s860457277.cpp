#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int main()
{
  ll h,w;
  cin >> h >> w;
  if(h == 1 || w == 1)
    cout << 1;
  else
    cout << h * w / 2 + ((h*w) % 2);
  
  
  
}
