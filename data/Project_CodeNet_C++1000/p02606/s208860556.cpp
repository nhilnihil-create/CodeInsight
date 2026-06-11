#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
const int maxn = 100010;
const int INF = INT_MAX/2;

int L, R, d;

int32_t main(){
	FAST
	cin >> L >> R >> d;
	int ans = 0;
	for (int i  = L; i <= R; i++) {
		if (i % d == 0) ans++;
	}
	cout << ans;
	
	

}







