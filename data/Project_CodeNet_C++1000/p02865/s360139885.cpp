#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

signed main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	if (n & 1) cout << n/2;
	else cout << n/2 - 1;
}
