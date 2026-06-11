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

ll v[N], ans[N];

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 32; i >= 0; i--){
		ll value = (1LL<<i), x = 0, valid = 1;
		for(int j = 0; j < n; j++)
			x ^= ((v[j]&value)==value);
		for(int j = 0; j < n; j++){
			ll newx = x ^ ((v[j]&value)==value);
			if(newx != ((v[j]&value)==value))
				valid = 0;
		}
		//cout << i <<" " << valid << endl;
		if(valid){
			for(int j = 0; j < n; j++)
				ans[j] += (((v[j]&value)==value) ? value:0);
		} else {
			for(int j = 0; j < n; j++)
				ans[j] += (!((v[j]&value)==value) ? value:0);
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] <<" ";
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
