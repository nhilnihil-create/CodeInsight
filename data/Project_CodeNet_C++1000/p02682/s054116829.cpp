#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())
#define res(x) cout<<((x)?"No\n":"Yes\n")
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef long double ld;

ll mod = 1e9+7;

void solution() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	int ans = 0;
	if(k > 0) {
		ans = min(k, a);
		k -= min(k, a);
	}

	if(k > 0) {
		k -= min(k, b);
	}

	if(k > 0) {
		ans -= min(k, c);
	}

	cout << ans << endl;
	
}

int main(){
	
	int t = 1;
	//cin >> t;
	
	while(t--)
		solution();
	
	return 0;
}
