#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const int N = 200005;

int f[N], v[N];

int mul(int a, int b){
	return 1ll * a * b % mod;
}

int pwr(int a, int b){
	int r = 1;
	for(; b; b >>=1, a = mul(a,a))
		if(b&1)
			r = mul(r,a);
	return r;
}

int add(int a, int b){
	a += b;
	if(a >= mod)a -= mod;
	return a;
}

void solve(){
	int n, k;
	cin >> n >> k;
	int x = pwr(10,100);
	for(int i = 0; i <= n; i++){
		v[i] = add(i, x);
		if(i)v[i] = add(v[i], v[i-1]);
	}
	int ans = 1;
	for(int i = k; i <= n; i++){
		ans = add(ans, ((v[n] - v[n-i] + mod)%mod - v[i-1] + mod)%mod + 1);
	}
	cout << ans << endl;
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
