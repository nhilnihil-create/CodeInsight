#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> d(n, vector<int>(n-1,0));
  vector<int> cnt(n*n,0);
  vector<int> v[n*n];
  rep(i,n)rep(j,n-1){
    cin >> d[i][j];
    d[i][j]--;
    if(j!=0){
      int a = i, b = d[i][j-1];
      if(a>b) swap(a,b);
      int c = i, e = d[i][j];
      if(c>e) swap(c,e);
      v[a*n+b].emplace_back(c*n+e);
      cnt[c*n+e]++;
    }
  }

  int ans = 0;
  int vs = 0;
  int pre = -1;
  queue<int> q;
  rep(i,n)rep(j,i){
    if(cnt[j*n+i]==0){
      q.push(j*n+i);
      vs++;
    }
  }
  while(pre!=vs){
    ans++;
    pre = vs;
    queue<int> nq;
    while(!q.empty()){
      int p = q.front(); q.pop();
      for(auto it:v[p]){
        cnt[it]--;
        if(cnt[it]==0){
          nq.push(it);
          vs++;
        }
      }
    }
    swap(q,nq);
  }
  if(vs!=n*(n-1)/2){cout << -1 << endl; return 0;}
  cout << ans << endl;
  return 0;
}