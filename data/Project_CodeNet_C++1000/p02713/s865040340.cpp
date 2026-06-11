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
const int N = 100005;

void solve(){
	int k;
	ll ans = 0;
	cin >> k;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++)
			for(int t = 1; t <= k; t++)
				ans += __gcd(__gcd(i,j), t);
	cout << ans << '\n';
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
