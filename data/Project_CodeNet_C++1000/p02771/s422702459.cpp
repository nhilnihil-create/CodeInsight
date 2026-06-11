#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,v,b;
  cin >> a >> v >> b;
  if(a==v && v != b||v==b && v != a|| b==a && v!=b )cout << "Yes" << endl;
  else if(a==b && b==v || a!=b && b!= v && v!=a)cout << "No" << endl;
}
