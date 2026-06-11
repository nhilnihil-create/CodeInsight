#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define int ll
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}

const int mod = 1e9+7;
int powmod(int n, int expo){
	int sum = 1;
	while(expo){
		if(expo & 1)	sum = sum * n % mod;
		n = n*n % mod;
		expo >>= 1;
	}
	return sum;
}

signed main(){
	IOS
	int n;	cin >> n;
	// ans = 10^n-2*9^n+8^n
	int x = (powmod(10, n)-2*powmod(9, n)+powmod(8, n)+2*mod)%mod;
	cout << x << endl;
}
