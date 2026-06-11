#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint k, q;
llint d[5005], dd[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> q;
	for(int i = 0; i < k; i++) cin >> d[i];
	
	llint n, x, m;
	for(int z = 0; z < q; z++){
		cin >> n >> x >> m;
		n--, x %= m;
		
		for(int i = 0; i < k; i++){
			dd[i] = d[i] % m;
			if(dd[i] == 0) dd[i] = m;
		}
		llint sum = 0;
		for(int i = 0; i < k; i++) sum += dd[i];
		
		llint a = sum/m, b = sum%m;
		llint ans = a * (n/k);
		llint pro = b * (n/k);
		//cout << a << " " << b << endl;
		ans += pro / m, pro %= m;
		x += pro;
		if(x >= m) ans++, x -= m;
		
		//cout << ans << endl;
		
		llint N = n%k;
		for(int i = 0; i < N; i++){
			x += dd[i];
			if(x >= m) x -= m, ans++;
		}
		cout << n - ans << endl;
	}
	
	return 0;
}