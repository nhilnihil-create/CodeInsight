#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0)
typedef long long ll;
#define int ll
#define swap(x, y)((x)^=(y)^=(x)^=(y))
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> matrix;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(c) c.begin(),c.end()
#define mp make_pair
#define pb push_back
#define ff first
#define tcase int _; cin>> _; for( ; _; --_)
#define ss second
#define endl '\n'
const int MAX = 1e6+1;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double DEG = 180/PI;
const int MOD = 1e9+7;
int mod(int x, int m){ if(x >= 0) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}
int gcd (int a, int b) {while(b){a = mod(a, b); swap(a, b);} return a;}
int lcm (int a, int b) {return a / gcd(a, b) * b;}
int fexp(int base, int exp, int m){
	int total = 1;
	for(;exp; exp>>=1){
		if(exp % 2 == 1) total = mod(((mod(total, m)) * (mod(base, m))), m);
		base= mod((mod(base, m) * mod(base, m)), m);
	}
	return total;
}

void solve(){
    int n;
    cin >> n;
    n-=3; 

    int c[2001];
    int inv[2001];
    c[0] = c[1] = inv[0] = inv[1] = 1;

    for(int i = 2; i <= 2000; ++i) c[i] = mod(i * c[i- 1], MOD);
    inv[2000] = fexp(c[2000], MOD-2, MOD);
    for(int i = 1999; i >=2; --i) inv[i] = mod(inv[i + 1] * (i + 1), MOD);

    int ans = 0;
    for(int i = 0; n >=0 ; ++i, n-=3){
        //int k = mod(c[n + i] * mod(fexp(c[n], MOD-2, MOD) * fexp(c[i], MOD-2, MOD), MOD), MOD);
        int k = mod(c[n + i] * mod(inv[n] * inv[i], MOD), MOD);
        ans = mod(ans + k, MOD);
    }
    cout<< ans<< endl;
}

int32_t main(){
	fastio;
	solve();
	return 0;
}

