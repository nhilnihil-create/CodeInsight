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

const int mx=200010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){ cin >> a[i]; }
  priority_queue<pair<ll,int>> q;
  rep(i,n){ cin >> b[i]; q.push({b[i],i}); }
  ll cnt = 0;
  while(!q.empty()){
    ll p; int pos;
    tie(p,pos) = q.top(); q.pop();
    int posl = pos-1; if(posl<0) posl+=n;
    int posr = pos+1; if(posr>=n) posr-=n;
    ll tmp = (b[pos]-a[pos])/(b[posl]+b[posr]);
    b[pos] -= (b[posl]+b[posr])*tmp;
    cnt+=tmp;
    if(a[pos]!=b[pos] && tmp){ q.push({b[pos],pos}); }
  }
  if(a==b){
    cout << cnt << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}