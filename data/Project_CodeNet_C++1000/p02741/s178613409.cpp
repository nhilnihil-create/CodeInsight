#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  vector<int> v = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int n;
  cin>>n;
  cout << v.at(n-1) << endl;
}