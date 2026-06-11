#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(n) (n).begin(),(n).end()
#define fi first
#define se second

typedef pair<int, int> PII;
typedef long long ll;

const int MOD = 1e9+7;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	int a[200000],ans=0;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll lo=0,hi=1e9;
	while(lo<=hi) {
		int mid = (lo+hi)/2;
		int cuts = 0;
		if (mid==0) {
			cout << 1 << "\n";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cuts+=(a[i]-1)/mid;
			if (cuts>k) break;
		}
		if (cuts<=k) ans=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout << ans << "\n";
}