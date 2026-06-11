#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define len(x) int((x).size())
#define res(x) cout << ((x) ? "YES\n" : "NO\n" )

typedef long long int integer;
typedef long double doble;

void solution() {
	int n, d;
	cin >> n >> d;
	d = (d * 2) + 1;
	int ans = (n/d);
	ans += (n%d) ? 1 : 0;
	cout << ans << endl;	
}
 
int main(){
	int t = 1;
	//cin >> t;
	while(t--) solution();
	return 0;
}