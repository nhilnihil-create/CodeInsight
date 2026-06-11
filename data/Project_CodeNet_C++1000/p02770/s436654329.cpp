#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000007;

LL k,q,n,x,m;
LL dd[5005],d[5005];

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> q;
	for(LL i = 0;i < k;i ++) cin >> dd[i];
	
	while(q --){
		LL ans = 0,sd = 0;
		cin >> n >> x >> m; x %= m;
		for(LL i = 0;i < k;i ++){
			d[i] = dd[i] % m;
			sd += d[i];
		}
		LL td = (n - 1) / k;
		ans = n - 1; ans -= (x + sd * td) / m;
		for(LL i = 0;i < k;i ++) if(!d[i]) ans -= td;
		
		x = (x + sd * td) % m;
		for(LL i = 0;i < (n - 1) % k;i ++){
			if(!d[i]) ans --;
			else{
				x += d[i];
				if(x >= m){
					x -= m;
					ans --;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}