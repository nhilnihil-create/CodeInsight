#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,c;
  cin >> a >> b >> c;
  int64_t d=c-a-b;
  if(4*a*b<d*d && d>0 )cout << "Yes" << endl;
  else cout << "No" << endl;
}
