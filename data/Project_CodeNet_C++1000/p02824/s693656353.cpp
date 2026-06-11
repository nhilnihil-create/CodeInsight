#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int INF = 0x7f7f7f7f;

typedef long long ll;



ll a[maxn];
ll sum[maxn];
vector <ll> vt;

bool cmp(int a , int b) {
	return a > b;
}

int main() {
	ll n , m , v , p;
	ios::sync_with_stdio(0);
	cin >> n >> m >> v >> p;
	vt.push_back(0); 
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1, cmp);
	int ans = p;
	for(int i = 1 ; i <= n ; i++) {
		sum[i] = sum[i - 1] + a[i];
	} 
	for(int i = p + 1 ; i <= n ; i++) {
		if(a[i] + m < a[p]){
			break;
		}
		else {
			if(m * v <= (p - 1) * m + (n - i + 1) * m+ (a[i] + m) * (i - p) - (sum[i - 1] - sum[p - 1])) {
				ans ++;
			}
			else {
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
