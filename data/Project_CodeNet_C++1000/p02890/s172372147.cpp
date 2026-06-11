#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef DEBUG
#define debug(x) cerr << #x << " " << x << '\n'
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f, N = 3e5 + 5;
int n, a[N], cnt[N], suf[N], cnt2[N], cnt3[N], pre[N];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	for(int i=1;i<=n;i++)
 	{
 		cin >> a[i];
 		cnt[a[i]]++;
 	}
 	for(int i=1;i<=n;i++)
 	{
 		if(cnt[i])
 		{
 			cnt2[cnt[i]] += cnt[i];
 			cnt3[cnt[i]]++;
 		}
 	}
 	for(int i=1;i<=n;i++) pre[i] = pre[i-1] + cnt2[i];
 	for(int i=n;i>=1;i--) suf[i] = suf[i+1] + cnt3[i];
 	for(int k=1;k<=n;k++)
 	{
 		int l = 1, r = n, ans = 0;
 		while(l<=r)
 		{
 			int mid = (l+r) >> 1;
 			if(suf[mid]+pre[mid-1]/mid>=k) ans = mid, l = mid + 1;
 			else r = mid - 1;
 		}
 		cout << ans << '\n';
 	}
	return 0;
}
