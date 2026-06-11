#include "bits/stdc++.h"

using namespace std;
 
const int inf = 1e8;
#define ll long long
#define fr(i,a,n) for (int i=a;i<n;i++)
#define rfr(i,n,a) for (int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define endl "\n"
typedef vector<int> VI;
typedef vector<ll> VL;

int n, m, k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	while (n) {
		for (int i = 22;i <= m;i++) {
			int cp = i;
			int d1 = i % 10,d10 = (i / 10) % 10;
			if (d1 < 2 || d10 < 2)
				continue;
			if (d1 * d10 == n) {
				cnt++;
			}
		}
		n--;
	}	
	cout << cnt << endl;
	return 0;
}