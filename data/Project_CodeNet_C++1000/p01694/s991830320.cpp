#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))
#define xyrange(x, minX, maxX, y, minY, maxY) (range(x, minX, maxX) && range(y, minY, maxY))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;
typedef vector<PII> VPII;


const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const int INF = INT_MAX / 2;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		VS ss;
		bool l = false, r = false;
		rep (i, n) {
			string s;
			cin >> s;
			ss.pb(s);
		}
		int ans = 0;
		bool flag = false;
		for (string s : ss) {
			if (s == "lu") l = true;
			else if (s == "ru") r = true;
			else if (s == "ld") l = false;
			else r = false;
			if (l && r && !flag) {
				flag = true;
				ans++;
			}
			if (!l && !r && flag) {
				flag = false;
				ans++;
			}
		}
		cout << ans << endl;

	}
	return 0;
}