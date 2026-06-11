#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

int main()
{
  int n;
  string s, t;

  cin>>n;
  cin>>s>>t;

  rep(i,s.size()) {
    cout<<s[i]<<t[i];
  }
  cout<<endl;

  return 0;
}