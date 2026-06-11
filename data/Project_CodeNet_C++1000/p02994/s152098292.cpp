#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n,l;
  cin >> n >> l;
  vi azi(n);
  int sum1 = 0, sum2 = 0;
  rep(i,n){
    azi[i] = l + i;
    sum1 += azi[i];
  }
  int a = 1000, ans, sa ;
  rep(i,n){
    sum2=0;
    for(int j=0;j<n;j++){
      
      if(i==j)continue;
      sum2 += azi[j];
    }
    sa = abs(sum1 - sum2);
    if(a > sa) ans = sum2;
    a = min(sa,a);
  }
  cout << ans << endl;
}
