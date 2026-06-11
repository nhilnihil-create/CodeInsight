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
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
  int n;
  cin >> n;
  int x[n],y[n];
  rep(i,n)cin >> x[i] >> y[i];
  int mx1=-INF,mn1=INF,mx2=-INF,mn2=INF;
  rep(i,n){
    chmax(mx1,x[i]+y[i]);
    chmin(mn1,x[i]+y[i]);
    chmax(mx2,x[i]-y[i]);
    chmin(mn2,x[i]-y[i]);
  }
  cout << max(mx1-mn1,mx2-mn2) << endl;
}