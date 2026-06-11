#include<bits/stdc++.h>
#define rep(i, x, n) for(int i = x; i < n; i++)
#define repr(i, x, n) for(int i = x; i > n; i--)
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define yes puts("YES")
#define no puts("NO")
#define PI 3.141592653589793238462643383279
const long long iinf = INT64_MAX - 1;
const int inf = INT32_MAX - 1;
const int MOD = (1e6+3);
int dir4[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dir8[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int knight[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
using namespace std;

void solve()
{
    int w, s; cin >> s >> w;
    if(w >= s) cout << "unsafe";
    else cout << "safe";

}
#define testcases 0             // 0 -> no test case. 1 -> test case
int main()
{
	int t = 1;

    if(testcases) cin >> t;

	// int i = 1;
	while(t--){
	// cout << "Case #" << i++ << ": \n";
	solve();
	// if(t)printf("\n");
	}
	return 0;
}