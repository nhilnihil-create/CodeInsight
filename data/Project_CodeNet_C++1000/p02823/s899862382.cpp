#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  ll n,a,b; cin>>n>>a>>b;

  if ((b-a)%2 == 0) {
    cout << (b-a)/2 << endl;
  } else {
    if (a-1 < n-b) {
      ll x = a-1;
      a -= x;
      b -= x+1;
      cout << x+1+(b-a)/2 << endl;
    } else {
      ll x = n-b;
      a += x+1;
      b += x;
      cout << x+1+(b-a)/2 << endl;
    }
  }

  return 0;
}
