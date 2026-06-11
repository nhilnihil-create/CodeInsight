#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;

vector<ll> ans;
ll V,E;
vector<ll> vec[10000];
vector<ll> che(10000,0);
vector<ll> path(10000,0);

void dfs(ll k){
  if(path[k] == 0){
    ans.push_back(k);
    for(auto itr:vec[k]){
      path[itr]--;
      dfs(itr);
    }
  }else{
    //path[k]--;
  }
}

int main(){
  cin >> V >> E;
  rep(i,E) {
    cin >> t1 >> t2;
    vec[t1].push_back(t2);
    che[t2]=1;
    path[t2]++;
  }
  rep(i,V){
    if(che[i] == 0){
      dfs(i);
    }
  }
  ull len = ans.size();
  rep(i,len){
    cout << ans[i] << endl;
  }
}
