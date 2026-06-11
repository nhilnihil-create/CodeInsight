/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

struct event{

  long long x;
  long long hp;
  int mon;

  event(ll x,int mon,ll hp):x(x),mon(mon),hp(hp){}

  bool operator<(const event a) const{
    if(x != a.x)return this->x > a.x;
    else return this->mon > a.mon;
  }
  void print(){
  	cerr << x << ' ' << hp << ' ' << mon << '\n';
  }
};

int main(int argc, char const *argv[])
{
  ioboost();

  ll n,d,a;cin >> n >> d >> a;
  vector<pl> m(n);

  priority_queue<event> q;

  rep(i,n){
    cin >> m[i].first >> m[i].second;
    event e(m[i].first,1,m[i].second);
    q.push(e);
  }

  long long ans = 0;
  long long dam = 0;

  while(q.size()){
    event e = q.top();q.pop();

    if(e.mon){

      ll cnt = max(0LL,(e.hp - dam + a - 1) / a);

      ans += cnt;
      dam += cnt * a;

      if(cnt){
      	event bomb(e.x + 2*d + 1,0,-cnt*a);
      	q.push(bomb);
      }

    }else{

      dam += e.hp;

    }
  }

  cout << ans << '\n';


  return 0;
}
