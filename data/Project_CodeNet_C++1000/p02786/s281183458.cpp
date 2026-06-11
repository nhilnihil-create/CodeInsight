#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1001001001;

ll vs(ll x){
  if(x==1)return 1;
  x /=2;
  return (1+2*vs(x));
}

int main(){
  ll H;
  cin >> H;
  ll ans = vs(H);
  cout << ans << endl;
  return 0;

}
