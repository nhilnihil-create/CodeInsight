#include <iostream>
#include <string>
#include <algorithm>
#define llint long long
#define inf ((llint)1e18)

using namespace std;

llint n;
llint a[300005], s[300005];
llint b[300005], bmax[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[x]++;
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	for(int i = 1; i <= n+1; i++){
		if(a[i] > 0) b[i] = (n-s[i-1])/a[i] + i;
		else b[i] = inf;
	}
	for(int i = 1; i <= n+1; i++) bmax[i] = max(bmax[i-1], b[i]);
	
	llint ans;
	for(llint i = 1; i <= n; i++){
		
		llint ub = n+1, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(bmax[mid] > i) ub = mid;
			else lb = mid;
		}
		ans = (n - s[ub-1]) / (i - (ub-1));
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}