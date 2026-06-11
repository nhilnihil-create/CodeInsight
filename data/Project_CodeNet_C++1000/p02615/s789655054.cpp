#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int arr[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n);
	long long ans = 0LL + arr[n];
	int cnt = n - 2;
	for(int i = n - 1; i >= 1; i --)
	{
		if(cnt <= 2){
			ans += cnt * arr[i];
			break;
		}
		ans += 2LL * arr[i];
		cnt -= 2;
	}
	printf("%lld\n", ans);
	return 0;
} 