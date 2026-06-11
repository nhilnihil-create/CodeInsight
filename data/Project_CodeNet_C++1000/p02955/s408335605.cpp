#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  rep(i,n)cin >> a[i];
  int sum = 0;
  rep(i,n)sum+=a[i];
  set<int> cand;
  for(int i=1;i*i<=sum;i++){
    if(sum%i!=0)continue;
    cand.insert(i);
    cand.insert(sum/i);
  }
  int ans=1;
  for(int t:cand){
    //cout << t << endl;
    int d[n];
    rep(i,n){
      d[i]=a[i]%t;
    }
    sort(d,d+n);
    ll need=0;
    {
      ll sum_mod = 0;
      rep(i,n)sum_mod+=d[i];
      int w = sum_mod/t;
      rep(i,n-w)need+=d[i];
    }
    if(need<=k)ans = t;
  }
  cout << ans << endl;
}