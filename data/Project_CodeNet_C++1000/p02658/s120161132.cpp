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

ll v[N];

void solve(){
	int n;
	cin >> n;
	double ans = 0.0;
	bool zero = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] == 0)zero = 1;
		ans += log10(v[i]);
	}
	if(zero)cout << 0 << endl;
	else{
		if(ans > 18)cout << -1 << endl;
		else{
			ll res = 1;
			for(int i = 0; i < n; i++)
				res *= v[i];
			cout << (res<=1000000000000000000?res:-1) << '\n';
		}
	}
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
