#include <bits/stdc++.h>
using namespace std;


int main(){
  int a,b,c;cin>>a>>b>>c;
  int tmp = a - (b + c);
  if (tmp < 0)
  {
    cout << abs(tmp) << endl;
  }
  else
  {
    cout << 0 << endl;
  }

}