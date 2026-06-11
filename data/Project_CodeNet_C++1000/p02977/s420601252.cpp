#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  int N; cin >> N;
  int tn = N; while(tn%2==0) tn /= 2;
  if (tn==1) { cout << "No" << endl; return 0; }

  cout << "Yes" << endl;
  cout << 1 << " " << 2 << endl; cout << N+1 << " " << N+2 << endl;
  cout << 2 << " " << 3 << endl; cout << N+2 << " " << N+3 << endl;
  cout << 3 << " " << N+1 << endl;

  for (int i=4; i+1<=N; i+=2) {
    cout << 1 << " " << i << endl; cout << i << " " << i+1 << endl;
    cout << 1 << " " << N+i+1 << endl; cout << N+1+i << " " << N+i << endl;
  }
  if (N%2==0) {
    cout << N << " " << N/tn << endl;
    cout << N*2 << " " << N*2-N/tn+1 << endl;
  }
  return 0;
}