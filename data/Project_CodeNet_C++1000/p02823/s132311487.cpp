#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  if((b-a)%2 == 0) cout << (b-a)/2 << endl;
  else{
    ll ans;
    if(a-1 <= n-b){
      ans = (a-1)+1+(b-a)/2;
    }
    else ans = (n-b)+1+(n-(a+n-b+1))/2;
    cout << ans << endl;
  }
}
