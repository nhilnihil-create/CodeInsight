#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  for(;;){
    c -= b;
    if(c<=0){
      cout << "Yes" << "\n";
      break;
    }
    a -= d;
    if(a<=0){
      cout << "No" << "\n";
      break;
    }
  }
}