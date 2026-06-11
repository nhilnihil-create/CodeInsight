#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int n,k;cin>>n>>k;
  if (k != 1)
  cout << n - k << endl;
  else
  cout << 0 << endl;
}