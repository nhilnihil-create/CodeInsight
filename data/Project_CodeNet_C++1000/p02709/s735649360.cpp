//Solution by Tima
#include <bits/stdc++.h>
 
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
#define all(x) x.begin(), x.end()
 
using namespace std;    
const int N = 2020, mod = int(1e9)  + 7; 

int n;
pair<int,int> a[N];

ll dp[N][N];

ll calc(int l,int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	ll v = a[r - l + 1].f, id = a[r - l + 1].s;
	dp[l][r] = max(calc(l + 1, r) + v * abs(id - l), calc(l, r - 1) + v * abs(id - r));
	return dp[l][r];
}

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i].f);
		a[i].s = i;
	}
	sort(a + 1, a + n + 1);

	memset(dp, -1, sizeof(dp));

	cout << calc(1,n);


return 0;
}