#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	fastio;
	ll a, b; cin >> a >> b;
	if(a > b) swap(a, b);
	if((b - a) % 2) cout << "IMPOSSIBLE" << endl;
	else{
		cout << (a + b) / 2 << endl;
	}
	return 0;
}

