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
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  int p[n];
  rep(i,n)cin >> p[i];
  rep(i,n)p[i]--;
  int ind[n];
  rep(i,n)ind[p[i]]=i;
  set<int> s;
  ll ans = 0;
  drep(i,n){
    s.insert(ind[i]);
    auto it = s.find(ind[i]);
    ll c = 0;
    {
      vector<ll> l(2,-1);
      vector<ll> r(2,n);
      auto itl = it;
      auto itr = it;
      rep(j,2){
        if(itl==s.begin())break;
        itl--;
        l[j]=*itl;
      }
      rep(j,2){
        itr++;
        if(itr==s.end())break;
        r[j]=*itr;
      }
      c = (l[0]-l[1])*(r[0]-*it)+(*it-l[0])*(r[1]-r[0]);
    }
    ans += c*(i+1);
  }
  cout << ans << endl;
}