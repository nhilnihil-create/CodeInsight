# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], sum[N];
map < int, int > f; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	long long ans = 0, cur = 0; 
	cin >> n >> k;
	f[0] = 1; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i] - 1) % k;
	}
	for(int i = 1; i <= n; i++){
		if(i >= k)f[sum[i - k]]--;
		ans += f[sum[i]];
		f[sum[i]]++;
	}
	cout << ans << endl;
}