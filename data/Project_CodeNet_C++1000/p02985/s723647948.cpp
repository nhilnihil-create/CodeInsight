#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll INF = 1000000007;
vector<vector<int>> g;
ll k;
ll ans;
vector<ll> ruijo;

// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x); // 再帰的に解く
	y -= a / b * x;
	return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
	return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)mod m
long long modinv(long long a, long long m) {
	long long x, y;
	extGCD(a, m, x, y);
	return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}


void dfs(int now, int p) {
  if(now==0){
	ans *= ruijo[k - 1];
	ans %= INF;
    if(k-sz(g[now])-1>=0){
     ans *= modinv(ruijo[k - sz(g[now])-1], INF);
    }else ans=0;
    ans%=INF;
  }else if(sz(g[now])>1){
    if(k-2>=0){
     ans*=ruijo[k-2];
    }else ans=0;
    ans%=INF;
    if(k-sz(g[now])-1>=0){
     ans*=modinv(ruijo[k-sz(g[now])-1],INF);
    }else ans=0;
    ans%=INF;
  }
    rep(i,sz(g[now])){
      if(g[now][i]==p) continue;
      dfs(g[now][i],now);
    }
}

int main() {
	int n;
	cin >> n >> k;
	g.resize(n);
	rep(i, n - 1) {
		int ai, bi;
		cin >> ai >> bi;
		ai--; bi--;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	ruijo.resize(k+1);
	ruijo[0] = (ll)1;
	rep(i, k)ruijo[i + 1] = ruijo[i] * ((ll)i + 1) % INF;
    ans=k;
	dfs(0, -1);
	cout << ans << endl;
}
