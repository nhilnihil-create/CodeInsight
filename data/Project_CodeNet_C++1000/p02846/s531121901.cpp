#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll x, ll y)
{
    ll temp;
    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }
    return (x);
}

int main() {
  ll t1,t2;
  cin >> t1 >> t2;
  ll a1,a2;
  cin >> a1 >> a2;
  ll b1,b2;
  cin >> b1 >> b2;

  ll num = gcd(t1,t2);
  num = gcd(num,a1);
  num = gcd(num,a2);
  num = gcd(num,b1);
  num = gcd(num,b2);

  t1 /= num; t2 /= num; a1 /= num; a2 /= num; b1 /= num; b2 /= num;

  ll p,q;
  p = (a1-b1)*t1;
  q = (a2-b2)*t2;

  if(p>0){
    p *= -1;
    q *= -1;
  }

  if(p+q<0){
    cout << 0 << endl;
    return 0;
  }
  else if(p+q==0){
    cout << "infinity" << endl;
    return 0;
  }

  ll s = -p / (p+q);
  ll t = -p % (p+q);

  if(t==0) cout << s*2 << endl;
  else cout << s*2 + 1 << endl;



}

