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

int main() {
	fast;
	cin.tie(0);
	lld n;
	cin >> n;
	int a, b, c, d;
	a = 0, b = 0, c = 1;
	
	if (n == 1) cout << 0 << endl;
	else if (n == 2) cout << 0 << endl;
	else if (n == 3) cout << 1 << endl;
	else {
		for (int i = 4; i <= n; i++) {
			d = c + a;
			d %= MOD;
			a = b;
			b = c;
			c = d;
		}
		
		cout << d << endl;
	}
}
