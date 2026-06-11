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
typedef pair <ll, int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const int N = 200005;

ll v[N];

void solve(){
	int n;
	ll x = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++)
		x ^= v[i];
	for(int i = 0; i < n; i++){
		cout << (v[i] ^ x) <<" ";
	}cout << endl;
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
