#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;

int dp1[3050][3050];
int dp2[3050][3050];
int a[3050],b[3050];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  
    int n,t; cin >> n >> t;
    rep2(i,1,n+1) cin >> a[i] >> b[i];  
    m0(dp1); m0(dp2);
  
    rep2(i,1,n+1)rep(j,t+1){
		dp1[i][j] = dp1[i-1][j];
        if(j-a[i] >= 0)dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i]] + b[i]);
    }
    for(int i = n; i >= 1; i--)rep(j,t+1){
        dp2[i][j] = dp2[i+1][j];
		if(j-a[i] >= 0) dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-a[i]] + b[i]); 
    }
  
    int ans = 0;
    rep2(i,1,n+1)rep(j,t) ans = max(ans, dp1[i-1][j]+dp2[i+1][t-j-1]+b[i]);
    cout << ans << endl;

    return 0;
}