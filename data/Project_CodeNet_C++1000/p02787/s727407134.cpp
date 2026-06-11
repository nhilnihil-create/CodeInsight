#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
#define chmax(a,b) if(b>a) a = b
#define chmin(a,b) if(b<a) a = b
typedef long long ll;
using namespace std;



int dp[20050];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int h,n; cin >> h >> n;
        vector<int> a(n), b(n);
        int amax = 0;
        rep(i,n){
                cin >> a[i] >> b[i];
                chmax(amax,a[i]);
        }

        rep(i,20050) dp[i] = 1001001001;
        dp[0] = 0;

        rep(i,20050){
                rep(j,n){
                        int ni = min(h, i+a[j]);
                        chmin(dp[ni],dp[i] + b[j]);
                }
        }
        cout << dp[h] << endl;

        return 0;
}