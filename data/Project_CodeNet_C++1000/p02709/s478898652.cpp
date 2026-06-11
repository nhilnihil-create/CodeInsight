#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define per(i,n) for (int i=n-1; i>=0; --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
const int mod = 1000000007;
//const int mod = 998244353;

ll dp[2001][2001];

int main(){
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(rall(a));
    //rep(i,n)cout<<a[i].first<<endl;
    
    for(int i=1; i<=n; i++){
        for(int x=0; x<=i; x++){
            
            int y = i-x;
            ll  c = a[i-1].first;
            ll  p = a[i-1].second;
            if(x)dp[x][y] = max(dp[x][y], dp[x-1][y] + c*abs(p-(x-1)));
            if(y)dp[x][y] = max(dp[x][y], dp[x][y-1] + c*abs((n-y)-p));
        }
    }
    ll ans = 0;
    rep(i,n+1){
        ans = max(ans, dp[i][n-i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
