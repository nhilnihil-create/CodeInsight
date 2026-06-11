#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

struct mons{
  ll X,A;
  bool operator<(const mons& other){return X < other.X;}
};
class BIT{
  public:
  vector<ll> s;
  const int n;
  BIT(int N) : s(N+1,0),n(N){}
  ll sum(int i){
    ll res = 0;
    while(i){
      res += s[i];
      i -= i & -i;
    }
    return res;
  }
  ll sum(int l,int r){
    return sum(r)-sum(l-1);
  }
  void add(int pos,ll val){
    while(pos <= n){
      s[pos] += val;
      pos += pos & -pos;
    }
  }
};

int main(){
  
  ll n,d,a;
  cin >> n >> d >> a;
  vector<mons> v(n);
  rep(i,n)cin >> v[i].X >> v[i].A;
  sort(ALL(v));
  BIT bit(n+10);
  ll res = 0;
  rep(i,n){
    ll k = bit.sum(i+1);
    if(v[i].A - k <= 0)continue;
    ll sum = (v[i].A-k+a-1)/a;
    res += sum;
    bit.add(i+1,a*sum);
    ll left = 0,right = n;
    while(right-left > 1){
      ll mid = (right+left)/2;
      if(v[mid].X > v[i].X+2*d)right = mid;
      else left = mid;
    }
    bit.add(left+2,-a*sum);
  }
  cout << res << endl;





  return 0;
}