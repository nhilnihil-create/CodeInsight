#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e4 + 6.66;
const int MAXM = 1e6 + 6.66;
vi g[MAXN];
int d[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  FOR(i,0,m) {
    int x,y;cin >> x >> y;
    d[x]++;
    g[y].pb(x);
  }
//  F0R(i,1,n) {
//    sort(g[i].begin(),g[i].end());
//    reverse(g[i].begin(),g[i].end());
//  }
  queue<int> q;
  stack<int> ans;
  RFOR(i,0,n) if( d[i]==0 ) q.push(i);
  while(q.size()) {
    ans.push(q.front());
    int i = q.front();q.pop();
    for(auto x : g[i])
    {
      d[x]--;
      if(!d[x]) q.push(x);
    }
  }
  if(ans.size()!=n) cout << "Sandro fails." << endl;
  else
    while(ans.size()) cout << ans.top() << "\n",ans.pop();
  cout << endl;
	return 0;
}