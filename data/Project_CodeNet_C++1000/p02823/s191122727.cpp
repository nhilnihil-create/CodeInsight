#include<bits/stdc++.h>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  ll n,a,b; cin >> n >> a >> b;
  if((b-a)%2==0) cout << (b-a)/2;
  else{
    ll ans = min(max(a-1,b-1),max(n-a,n-b));
    if(a-1 < n-b){
      b -= a;
      chmin(ans,(b-1)/2+a);
    }else{
      a += n-b+1;
      chmin(ans,(n-a)/2+n-b+1);
    }
    cout << ans;
  }
  cout << "\n";
  return 0;
}
