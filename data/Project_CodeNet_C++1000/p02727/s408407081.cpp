#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<P> vec;
  vector<ll> p(A);
  REP(i, A){
    cin >> p[i];
    vec.push_back(make_pair(p[i],0));
  }
  vector<ll> q(B);
  REP(i, B){
    cin >> q[i];
    vec.push_back(make_pair(q[i],1));
  }
  vector<ll> r(C);
  REP(i, C){
    cin >> r[i];
    vec.push_back(make_pair(r[i],2));
  }
  sort(ALL(vec));
  reverse(ALL(vec));

  ll x=0,y=0,z=0;
  ll ans = 0;
  REP(i,vec.size()){
    if(vec.at(i).second==0){
      if(x+1<=X&&y<=Y&&x+1+y+z<=X+Y){
        ans+=vec.at(i).first;
        x++;
      }
    }else if(vec.at(i).second==1){
      if(x<=X&&y+1<=Y&&x+y+1+z<=X+Y){
        ans+=vec.at(i).first;
        y++;
      }
    }else if(vec.at(i).second==2){
      if(x<=X&&y<=Y&&x+y+z+1<=X+Y){
        ans+=vec.at(i).first;
        z++;
      }
    }
  }
  cout << ans << endl;
}