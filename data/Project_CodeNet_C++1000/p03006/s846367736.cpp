#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn = 1e3 + 10;
map<pii,int> mp;
pii a[maxn];
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			mp[pii(a[i].first - a[j].first,a[i].second - a[j].second)]++;
		}
	}
	int mx = 0;
	for (auto it : mp) {
		mx = max(mx,it.second);
	}
	printf("%d\n",n - mx);
	return 0;
}