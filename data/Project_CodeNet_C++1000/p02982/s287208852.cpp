#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 100005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long 

#define mod  1000000007



int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	int a[n+5][m+6];
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	
	for(int i = 0; i < n-1; i ++){
		int x = 0;
		for(int j = i + 1; j < n; j ++){
			for(int z = 0; z < m; z ++){
				x += (a[i][z] - a[j][z])*(a[i][z] - a[j][z]);
			}
			if(floor(sqrt(x)) == ceil(sqrt(x))){
				ans ++;
			}
			x = 0;
		}
	}
	cout << ans;
	return 0;
	
}