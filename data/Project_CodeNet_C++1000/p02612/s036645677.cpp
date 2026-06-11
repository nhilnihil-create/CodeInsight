#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n,a; cin >> n;
  if(n%1000==0) {cout << 0 << endl;}
  else{cout << 1000-(n%1000) << endl;}
}