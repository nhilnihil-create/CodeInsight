#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int h,n;
    cin >> h >> n;
    vector<int> dp(h+1,1e9);
    dp[0]=0;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        repr(j,1,h+1) {
            if (j-a>=0) dp[j]=min(dp[j],dp[j-a]+b);
            else dp[j]=min(dp[j],b);
        }
    } 
    cout << dp[h] << endl;

    return 0;
}
