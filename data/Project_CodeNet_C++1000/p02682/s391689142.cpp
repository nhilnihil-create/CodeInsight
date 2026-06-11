#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
  int a,b,c,k; cin >> a >> b >> c >> k;
  if(k<=a){
    cout << k << "\n";
  }else if(k<=a+b){
    cout << a << "\n";
  }else{
    cout << a+(k-(a+b))*-1 << "\n";
  }
}