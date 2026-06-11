#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int main()
{
  int H, W, K; cin >> H >> W >> K;
  vector<string> tmp(H);
  rep(i, 0, H) cin >> tmp[i];
  vector<vector<string>> G(H, vector<string>(W));
  rep(i, 0, H){
    rep(k, 0, W){
      G[i][k] = tmp[i][k];
    }
  }
  
  ll ans = 0;
  for(int bit = 0; bit < (1 << H); ++bit){
    for(int bit2 = 0; bit2 < (1 << W); ++bit2){
      ll cnt = 0;
      rep(i, 0, H){
        rep(k, 0, W){
          if(!(bit2 & (1 << k)) && !(bit & (1 << i)) && G[i][k] == "#") ++cnt;
        }
      }
      if(cnt == K) ++ans;
    }
  }
  cout << ans << endl;

}
