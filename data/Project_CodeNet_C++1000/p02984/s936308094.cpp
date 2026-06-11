#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n),x(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  for(int i=1; i<n-1; i+=2){
    sum-=2*a[i];
  }
  x[0]=sum;
  for(int i=0; i<n-1; i++){
    x[i+1]=2*a[i]-x[i];
  }
  rep(i,n) cout << x[i] << " ";


  return 0;
}
