#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
signed main()
{
  int a,b,c,k; cin >> a >> b >> c >> k;
  if(k<=a){
    cout << k << "\n";
    return 0;
  }
  if(k<=a+b){
    cout << a << "\n";
    return 0;
  }
  if(k>a+b){
    cout << a+(k-(a+b))*-1 << "\n";
    return 0;
  }
}