#include <bits/stdc++.h>
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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  int st = -1;
  rep(i,(1<<n)){
    int x; cin >> x;
    mp[x]++;
    st = max(st, x);
  }
  mp[st]--;
  if(mp[st]==0){ mp.erase(st); }
  priority_queue<int> q;
  q.push(st);
  while(!mp.empty()){
    priority_queue<int> q2;
    while(!q.empty()){
      auto p = q.top(); q.pop();
      auto pos = mp.lower_bound(p);
      if(pos==mp.begin()){ cout << "No" << ln; return 0; }
      pos--;
      pos->S--;
      q2.push(p);
      q2.push(pos->F);
      if(pos->S==0){ mp.erase(pos); }
    }
    swap(q2,q);
  }
  cout << "Yes" << ln;
  return 0;
}