#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6+10;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 0; 
	cin >> n;
	vector<int> a(n), cnt(MX);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		cnt[a[i]]++;
	}
	vector<bool> good(MX + 1, 1);
	for (int i = 1; i <= MX; ++i){
		if (cnt[i]){
			for (int j = i + i; j <= MX; j += i){
				good[j] = 0;
			}
		}
	}
	for (auto x: a){
		if (good[x] && cnt[x] == 1) ans++;
	}
	cout << ans << '\n';

}


