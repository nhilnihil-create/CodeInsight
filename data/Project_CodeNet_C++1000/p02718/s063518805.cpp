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

int v[N];

void solve(){
	int n,m;
	cin >> n >> m;
	int total = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		total += v[i];
	}
	double x = (double)total/(4.0*(double)m);
	for(int i = 0; i < n; i++)
		ans += (double)v[i]>=x;
	cout << (ans >= m ? "Yes":"No") << "\n";
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
