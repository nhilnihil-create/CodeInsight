#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  
  vector<int> y=x;
  sort(y.begin(),y.end());
  int a=1000000007;
  for(int i=*y.begin();i<=*y.rbegin();++i){
    int v=0;
    rep(j,n){
      v+=(y[j]-i)*(y[j]-i);
    }
    a = min(a,v);
  }
  cout << a << endl;
  return 0;
}
