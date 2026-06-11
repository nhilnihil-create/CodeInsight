#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define PB push_back
#define F first
#define S second

typedef unsigned long long llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int INF = 1e9+10;
const ll MOD = 1e9+7;

void solve(){
	int n, k, c; cin >> n >> k >> c;
	string s; cin >> s;

	bitset<200007> to(0), from(0);
	bool ok = true;
	int aux = 0;
	for(int i = 0; i < n; i++){
		if(!ok) aux++;
		else if(ok && s[i] == 'o'){
			to[i] = 1;
			ok = false;
		}
		if(aux == c){
			ok = true;
			aux = 0;
		}
	}
	aux = 0;
	ok = true;
	for(int i = n-1; i >= 0; i--){
		if(!ok) aux++;
		else if(ok && s[i] == 'o'){
			from[i] = 1;
			ok = false;
		}
		if(aux == c){
			ok = true;
			aux = 0;
		}
	}

	if((int)(to&from).count() > k){
		return;
	}

	FOR(i, n)
		if(to[i] && from[i])
			cout << i+1 << '\n';

}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t=1; //cin >> t;
	while(t--){
		solve();
	}

	return 0;
}