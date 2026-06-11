#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  int k,x;
  cin>>k>>x;
  rep(i,k-1) cout<<x-k+1+i<<" ";
  cout<<x<<" ";
  rep(i,k-1) cout<<x+i+1<<" ";
  cout<<endl;
  return 0;
}
