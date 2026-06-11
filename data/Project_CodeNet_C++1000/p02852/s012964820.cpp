#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
vector<int> moves;

signed main(){
	cin >> n >> m >> s;
	bool ok = true;
	for(int i = 1, now = 0; i <= n; ++i){
		if(i == n || s[i] == '0') 
			moves.push_back(i - now), ok &= (i - now <= m), now = i;
	}
	if(!ok) cout << -1;
	else {
		for(int i = (int)moves.size() - 1; i > 0; --i)
			if(moves[i] + moves[i - 1] <= m) moves[i - 1] += moves[i], moves[i] = 0;
		for(auto e : moves) if(e) cout << e << ' ';
	}
}