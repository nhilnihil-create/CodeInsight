#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  ll n,k; cin>>n>>k;
  vector<bool> bits(n);
  rep(i,k){
    ll d; cin>>d;
    rep(j,d){
      ll x; cin>>x;
      bits[x-1]=true;
    }
  }
  ll cnt=0;
  rep(i,n) if(bits[i]==false) cnt++;
  cout<<cnt<<endl;
  return 0;
}