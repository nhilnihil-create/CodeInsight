#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;

ll n;
map<ll, int> mp;
int ans=0;

int bs(int x){
  int ans=1;
  for(int i=x; i>0; i/=2){
    while((ans+i+1)*(ans+i)/2<=x){
      ans+=i;
    }
  }
  return ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  for(ll i=2; i*i<=n; i++){
    while(n%i==0){
      n/=i;
      mp[i]++;
    }
  }
  if(n>1) mp[n]++;
  trav(p, mp){
    ans+=bs(p.second);
  }
  cout << ans;
}