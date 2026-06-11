#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back 
#define eb emplace_back
#define mx *max_element
#define mi *min_element
#define fn for(int i =0 ;i <n;i++)
#define fn1 for( int i =1;i<=n;i++)
#define fm for(int j =0 ;j <m;j++)
#define fm1 for(int j =1;j<=m;j++)
#define fi first
#define se second
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
const int N = 1e6+5;
const int INF = 1e18L;
int ncr(int n,int r){if(n<r)return 0;int p=1,k=1;if(n-r<r)r=n-r;if(r!=0){while(r){p*=n;k*=r;int g=__gcd(p, k);p/=g;k/=g;n--;r--;}}else p=1;return p;}
#define pi acos(-1)
int ar[N];
int tree[2*N];
int dp[N];
int bit[N];
signed main(){
 	// #ifndef ONLINE_JUDGE
 	// freopen("input.txt","r",stdin);
 	// freopen("out2.txt","w",stdout);
 	// #endif
	SaveTime;
	int T=1;
	// cin >> T;
	while(T--){
		int n ;
		cin >> n ;
		if(n&1){
			cout << n/2 <<endl;
		}
		else
			cout <<n/2-1 <<endl;


	}
	
	return 0;
}
