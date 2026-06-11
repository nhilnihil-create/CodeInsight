#include<bits/stdc++.h>
#define fs first
#define se second
#define pb push_back
#define cppio ios::sync_with_stdio(false);cin.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;

const int maxn=1e6+5;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;

ll dp[maxn][4];

int main(){
	ll n;
	scanf("%lld",&n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){			
		dp[i][0]=(dp[i-1][0]*8)%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][1]*9)%mod;
		dp[i][2]=(dp[i-1][0]+dp[i-1][2]*9)%mod;
		dp[i][3]=(dp[i-1][3]*10+dp[i-1][2]+dp[i-1][1])%mod;
	}
	printf("%lld",dp[n][3]);
	return 0;
}
