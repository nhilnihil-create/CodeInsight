#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

int p[52];

int main(){
	fastio;
	int n; cin >> n;
	int bad = 0;
	for(int i = 0; i < n; ++ i) {
		cin >> p[i];
		p[i] --;
		if(p[i] != i) bad ++;
	}
	if(bad > 2) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}

