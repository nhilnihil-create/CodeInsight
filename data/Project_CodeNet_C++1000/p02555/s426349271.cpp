#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define MAX 100000+10
#define MOD 1000000007

ll fac[MAX],caf[MAX]; //factorial e inverso

ll deg(ll x,ll d){
	d %= MOD - 1;
    	if(d < 0)d += MOD - 1;
    	ll y = 1;
    	while (d) {
        	if (d & 1) y *= x, y %= MOD;
        	x *= x, x %= MOD;
        	d /= 2;
    	}
    	return y;
}
ll coeff(int n,int k){
	return fac[n] * caf[k] % MOD * caf[n - k] % MOD;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	fac[0] = caf[0] = 1;
	forn(i,1,MAX)fac[i] = i * fac[i - 1] % MOD, caf[i] = deg(fac[i], -1);
	int S; cin >> S;
	ll res = 0;
	
	forn(i,1,2000){
		int Sp = S-3*i;
		if(Sp < 0)break;
		ll add = coeff(i+Sp-1,i-1);
		res = ((res%MOD)+(add%MOD))%MOD;
	}
	if(res < 0)res += MOD;
	cout << res << '\n';
	
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
