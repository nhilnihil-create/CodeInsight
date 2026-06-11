#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
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
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> d1(n),d2(n);
  rep(i,n) cin >> d1[i] >> d2[i];
  bool f = false;
  rep(i,n-2){
    if(d1[i]==d2[i] && d1[i+1]==d2[i+1] && d1[i+2]==d2[i+2])
      f = true;
  }
  if (f) puts("Yes");
  else
    puts("No");
  return 0;
}