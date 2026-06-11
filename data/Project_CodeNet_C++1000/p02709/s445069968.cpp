#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}

int a[3000];
int dp[2005][2005];
vector<P> narabi;
signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a1;
        cin >> a1;
        narabi.pb(P(a1,i));
    }
    sort(narabi.begin(),narabi.end());
    reverse(narabi.begin(),narabi.end());
    for(int i=1;i<=n;i++){
        P ne = narabi[i-1];
        for(int j=0;j<=i;j++){
            int m1,m2;
            if(j==0) m1 = -1;
            else{
                m1 = dp[j-1][i-j] + abs(j-ne.second) * ne.first;
            }
            if(i-j == 0) m2 = -1;
            else{
                m2 = dp[j][i-j-1] + abs(n-(i-j)+1-ne.second) * ne.first;
            }
            dp[j][i-j] = max(m1,m2);
        }
    }
    int ans = -1;
    for(int j=0;j<=n;j++){
        ans = max(ans,dp[j][n-j]);
    }
    cout << ans << endl;
    return 0;
}