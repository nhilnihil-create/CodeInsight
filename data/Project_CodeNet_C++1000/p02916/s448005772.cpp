#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int inf = 1e9 + 7;
const int MAXN = 1e5 + 5;

	
int main(){		
	int n; cin >> n;
	vector<int> a(n), b(n), c(n-1);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	for(int i = 0; i < n-1; ++i)
		cin >> c[i];
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans+=b[a[i]-1];
		if(a[i]+1 == a[i+1]){
			ans+=c[a[i]-1];
		}
	}
	cout << ans << endl;

	return 0;
}
