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
typedef pair <int, int> ii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const double EPSILON = 0.001;
const int N = 200005;
int main(){
	fastio;
	ll ones, zer, none, k, ans = 0;
	cin >> ones >> zer >> none >> k;
	if(ones >= k){
		ans = k;
		k = 0;
	}else{
		ans += ones;
		k -= ans;
	}
	if(k > 0){
		if(zer >= k)
			k = 0;
		else
			k -= zer;
	}
	if(k > 0){
		ans -= min(k,none);
	}
	cout << ans << '\n';
	return 0;
}
