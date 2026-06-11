#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin>>x;
  int sho = x / 100;
  int sa = x - sho * 100;
  if(sa <= sho*5) {
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
  return 0;
}