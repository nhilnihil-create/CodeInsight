#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define mod 998244353
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<lld> vi;
typedef vector<vector<lld>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<lld, lld>> vpi;
typedef long long LL;

/*
f(n) = f(n-1) + f(n-3); n >= 6
f(3) = 1;	
f(4) = 1;
f(5) = 1;
*/

int f[2001];

constexpr void pre() {
	f[3] = f[4] = f[5] = 1;
	for (int i = 6; i <= 2000; i++) {
		f[i] = f[i-1] + f[i-3];
		f[i] %= MOD;
	}
}

int main() {
	fast;
	cin.tie(0);
	pre();
	
	lld n;
	cin >> n;
	
	cout << f[n] << endl;
}
