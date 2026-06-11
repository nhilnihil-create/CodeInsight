#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define vc vector
#define sz(v) (int)(v).size()
#define pb push_back
#define FF first
#define SS second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define pll pair<ll,ll>
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
typedef long double f80;
#define endl '\n'

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, d;
	cin >> m >> d;
	int tot = 0;
	fr(i, 10, d) {
		int val1 = i / 10, val2 = i % 10;
		if(val1 * val2 >= 1 && val1 * val2 <= m && val1 >= 2 && val2 >= 2) {
			tot++;
		}
	}
	cout << tot;
	return 0;
}