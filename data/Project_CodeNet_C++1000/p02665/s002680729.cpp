#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

const int MAX_N = 1e5+2;
const ll MX = 1e18;
int N;
ll A[MAX_N];

void solve()
{
	ll nonleaf = 1;
	for(int i=0;i<N+1;++i) {
        nonleaf -= A[i];
        if (nonleaf < 0) {
            cout << -1 << '\n'; 
			return;
        }
        nonleaf *= 2;
		if (nonleaf > MX) nonleaf = MX;
    }
    ll lower = accumulate(A,A+N+1,0LL);
	nonleaf = 1;
    ll ans = 0;
    for(int i=0;i<N+1;++i) {
        ans += min(nonleaf, lower);
        nonleaf -= A[i];
        nonleaf *= 2;
		if (nonleaf > MX) nonleaf = MX;
        lower -= A[i];
    }
    cout << ans << '\n';
}

int main() {
   	
    cin >> N;
    for(int i=0;i<N+1;++i) cin >> A[i];
	solve();	
	return 0;
}

