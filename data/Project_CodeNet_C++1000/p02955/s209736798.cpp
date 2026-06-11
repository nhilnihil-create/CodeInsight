#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0;i < n; ++i){
		cin >> a[i];
	}
	int sum = accumulate(a, a + n, 0);
	vector<int> div;
	for(int i = 1;i * i <= sum; ++i){
		if(sum % i == 0){
			div.push_back(i);
			div.push_back(sum/i);
		}
	}
	int ans = 0;
	for(int d : div){
		vector<int> mods(n);	
		for(int i = 0;i < n; ++i){
			mods[i] = (d - (a[i] % d)) % d;	
		}
		int tsum = accumulate(mods.begin(), mods.end(), 0);
		sort(mods.rbegin(),mods.rend());
		int moves = 0, ind = 0;
		while(tsum){
			moves += (d-mods[ind]) % d;
			tsum -= d;	
			++ind;
		}
		if(moves <= k){
			ans = max(ans, d); // don't make dumb assumptions
		}
	}
	cout << ans << '\n';
}
