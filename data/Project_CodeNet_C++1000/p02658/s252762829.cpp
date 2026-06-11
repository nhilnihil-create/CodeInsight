#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main()
{
  int n;
  ll t=1, a;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a;

    if(t == 0 || a == 0){
      t = 0;
    }
    else if ( t > 0 && t <= 1000000000000000000 / a) {
      t *= a;
    }
    else{
      t = -1;
    }
  }

  cout << t << endl;
}