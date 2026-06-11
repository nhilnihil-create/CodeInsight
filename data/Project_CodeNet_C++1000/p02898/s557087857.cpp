#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define len(x) int((x).size())
#define res(x) cout << ((x) ? "YES\n" : "NO\n" )
#define st first
#define nd second

typedef long long int integer;
typedef long double doble;

void solution() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	int x;
	while(n--) {
		cin >> x;
		if(x >= k) {
			ans++;
		}
	}
	cout << ans;
}
 
int main(){
	int t = 1;
	//cin >> t;
	while(t--) solution();
	return 0;
}