#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
const int maxn = 200010;
const int INF = INT_MAX/2;
const int mod = 1e9 + 7;

int n;
int nodes, edges;

int32_t main(){
	FAST
	cin >> n;
	
	for (int i =1; i<= n;i++) {
		nodes += i * (n - i + 1);
	}
	
	for (int i =0; i < n-1;i++) {
		int a,b; cin >> a >> b;
		if (a > b) swap(a,b);
		edges += a * (n - b + 1);
	}
	
	cout << nodes - edges;
	
}







