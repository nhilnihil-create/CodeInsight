#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;
ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  vector<vector<int>> ans(h, vector<int>(w, 0));
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(i < b){
        if(j < a) ans[i][j] = 0;
        else ans[i][j] = 1;
      }
      else{
        if(j < a) ans[i][j] = 1;
        else ans[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}