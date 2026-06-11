#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;	cin >> a >> b >> c;
  string x="No";
  if(a==b&&b!=c)	x="Yes";
  if(a==c&&a!=b)	x="Yes";
  if(b==c&&c!=a)	x="Yes";
  cout << x;
}