#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define rep2(i, n, m) for(int i=(int)n; i<=(int)m; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll inf=1LL << 60;
const ll MOD=1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll ans=0;
  if(n%2==0){
    n/=10;
    ans+=n;
    while(n>=5){
      n/=5;
      ans+=n;
    }
  }

  cout << ans << endl;

  return 0;
}