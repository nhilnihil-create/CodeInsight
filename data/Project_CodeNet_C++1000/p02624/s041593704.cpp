#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N; cin >> N;
  ll ans = 0;
  for(int i=1;i<=N;i++){
    ll n = N/i;
    ans += n*(i+i*n)/2;
  }
  cout << ans << endl;
}
