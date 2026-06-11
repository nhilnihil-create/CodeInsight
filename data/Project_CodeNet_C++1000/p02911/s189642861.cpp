#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int n,k,q;
cin >> n >> k >> q;
vector<int> a(n);
rep(i,q){
  int x;
  cin >> x;
  a.at(x-1)++;
}
rep(i,n){
  if(k-q+a.at(i) > 0) cout <<"Yes" << endl;
  else cout <<"No" << endl;
}
}
