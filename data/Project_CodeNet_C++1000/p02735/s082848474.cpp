#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
#define fi first
#define se second
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 9e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;

void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;

        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

//------------------------------------------------------------------------------------------

//const ll N = 1e5 + 1;
//vector<ll> adj[N];
//bool visited[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);

	ll h, w;
	cin>>h>>w;
	ll mat[h][w];
	char x;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>x;
			if(x=='.') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	ll dp[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i==0 && j==0) {
				dp[i][j] = mat[i][j];
			}
			else{
				if(mat[i][j] == 1){
					ll mi = INT_MAX;
					if(i>0 && j>0){
						if(mat[i-1][j]) mi = dp[i-1][j];
						else mi = dp[i-1][j] + 1;

						if(mat[i][j-1]) mi = min(mi, dp[i][j-1]);
						else mi = min(mi, dp[i][j-1] + 1);
						
						dp[i][j] = mi;
					}
					else if(i>0){
						if(mat[i-1][j]) dp[i][j] = dp[i-1][j];
						else dp[i][j] = dp[i-1][j] + 1;
					}
					else{
						if(mat[i][j-1]) dp[i][j] = dp[i][j-1];
						else dp[i][j] = dp[i][j-1] + 1;
					}
				}
				else{
					if(i>0 && j>0) dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
					else if(i>0) dp[i][j] = dp[i-1][j];
					else dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
	cout<<dp[h-1][w-1];

    return 0;
}
