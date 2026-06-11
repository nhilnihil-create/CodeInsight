 #include <bits/stdc++.h>
 using namespace std;
 
 #define ll long long
 #define endl "\n"
 
 const int mxn = 2001;
 ll dp[mxn][mxn];

 void selfmax(ll &a, ll b){
    a=max(a,b);
 }
 
 int main(){
     //
     //freopen("input.txt", "r", stdin);
     //
     ios::sync_with_stdio(0);
     cin.tie(0);
     int n; cin>>n;
     vector<pair<int,int>> a(n+1);

     for (int i=1; i<=n; ++i){
        cin>>a[i].first;
        a[i].second = i;
     }
     ll ans=0;
     sort(a.begin()+1, a.end());
     for (int i=n; i>=1; --i){
        for (int j=1; i+j-1<=n; ++j){
            ll score = 1LL * a[i].first * abs(a[i].second-j);
            if (i==1)
                ans=max(ans, dp[j][j]+score);
            else{
                selfmax(dp[j+1][i+j-1], (dp[j][i+j-1]+score));
                selfmax(dp[j][i+j-2], (dp[j][i+j-1]+1LL*a[i].first*abs(i+j-1-a[i].second)));
            }
        }
    }
    cout<<ans;
    return 0;
}