#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i =(b)-1;i>=(a);--i)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
int f1[maxn],f2[maxn];
int x[maxn],y[maxn],z[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,m;
	cin >> a >> b >> m;
	rep(i,0,a)cin >> f1[i];
	rep(i,0,b)cin >> f2[i];
	rep(i,0,m)cin >> x[i] >> y[i] >> z[i];
	int ans = *min_element(f1,f1+a) + *min_element(f2,f2+b);
	rep(i,0,m)ans = min(ans,f1[x[i]-1]+f2[y[i]-1] - z[i]);
	cout << ans; 
	return 0;
}
