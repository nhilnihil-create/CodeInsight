#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main()
{
  int n; cin >> n;
  ll num = 1,a;

  for(int i = 0; i < n; i++) {
    cin >> a;

    if(a > 0 && 1000000000000000000 / num >= a) {
      num *= a;
    }

    else if (a==0) {
      num = 0;
      break;
    }

    else{
      num = -1;
    }

  }

  cout << num;
}