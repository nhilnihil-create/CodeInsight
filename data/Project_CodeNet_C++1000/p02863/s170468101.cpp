#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=3003;
int a[mxn],b[mxn];
int dpl[mxn][mxn],dpr[mxn][mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,t; cin >> n >> t;
	for(int i=1; i<=n; i++)cin >> a[i] >> b[i];
	for(int i=1; i<=n; i++){
		for(int j=0; j<=t; j++){
			dpl[i][j] = max(dpl[i][j],dpl[i-1][j]);
			if(j>=a[i])dpl[i][j]=max(dpl[i][j],dpl[i-1][j-a[i]]+b[i]);
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=0; j<=t; j++){
			dpr[i][j] = max(dpr[i][j],dpr[i+1][j]);
			if(j>=a[i])dpr[i][j]=max(dpr[i][j],dpr[i+1][j-a[i]]+b[i]);
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++){ // i being the last plate
		int now = b[i];
		for(int j=0; j<t; j++){
			now = max(now,b[i]+dpl[i-1][j]+dpr[i+1][t-1-j]);
		}
		ans = max(ans,now);
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
