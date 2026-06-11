#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int mxn = 100;
vector<int> coins;
int n;

void solve() {
	int n;
    cin >> n;
    vector<int>a(n), b(n), c(n-1);
    for(int i=0; i<n; ++i){
        cin >> a[i];
        --a[i];
    }
    for(int i=0; i<n; ++i)
        cin >> b[i];
    for(int i=0; i<n-1; ++i)
        cin >> c[i];
    int ans = 0;
    for(int i=0; i<n; ++i){
        ans += b[a[i]];
        if(i > 0 && a[i] == a[i-1] + 1)
            ans += c[a[i-1]];
    }
    cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}
