#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n,m;
  cin >> n >> m ;
  vector<int> v(m);
  for(int i=0; i<m; ++i){
    cin >> v[i];
  }
  for(int i=0; i<m; ++i){
    n -= v[i];
  }
  cout << ((n<0)? -1:n) << "\n";
}