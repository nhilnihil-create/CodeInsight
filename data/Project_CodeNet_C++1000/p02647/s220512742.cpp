#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int>v(n);
  rep(i,n)cin >> v[i];
  rep(i,k){
    bool end = true;
    rep(j,n)if(v[j] != n)end = false;
    if(end)break;
    vector<int>imos(n + 1);
    rep(j,n){
      imos[max(0,j - v[j])]++;
      imos[min(n,j + v[j] + 1)]--;
    }
    rep(j,n)imos[j + 1] += imos[j];
    rep(j,n)v[j] = imos[j];
  }
  rep(i,n){
    if(i == n - 1)cout << v[i] << endl;
    else cout << v[i] << " ";
  }
  return 0;
}
