#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
/*vector<Type> v;
vector<Type> v();
vector<Type> v(n);
vector<Type> v(n, d);
vector<vector<Type>> vv;
vector<vector<Type>> vv();
vector<vector<Type>> vv(n);
vector<vector<Type>> vv(n, vector<Type>(m));
vector<vector<Type>> vv(n, vector<Type>(m, d));*/

int main() {
  string s,t,u;
  int a,b;
  cin>>s>>t>>a>>b>>u;
  if(u==s) a--;
  if(u==t) b--;
  cout<<a<<' '<<b;
  return 0;
}
