# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
map < int, set < int > > f; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	long long ans = 0, cur = 0; 
	cin >> n >> k;
	f[0].insert(0);
	for(int i = 1, a; i <= n; i++){
		cin >> a; 
		cur = (cur + a - 1) % k; 
		int er = i - k; 
		while(f[cur].size() && *f[cur].begin() <= er){
			f[cur].erase(f[cur].begin());
		}
		ans += f[cur].size();
		f[cur].insert(i);
	}
	cout << ans << endl;
}