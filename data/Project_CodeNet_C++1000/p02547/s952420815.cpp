#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int ans;

void solve(void){
	int n;
	cin >> n;
	pair<int, int> p[n];
	for(int i = 0; i < n; i++){
		cin >> p[i].first >> p[i].second;
	}
	for(int i = 0; i + 2 < n; i++){
		if(p[i].first == p[i].second && p[i+1].first == p[i+1].second &&
			p[i+2].first == p[i+2].second){
				cout << "Yes\n";
				return;
			}
	}
	
	cout << "No\n";
	
}

signed main() {
int t = 1;
// cin >> t;    
	while(t--)
    solve();

    return 0;
}
