#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題

int main() {
    int n;
    cin >> n;
    int w[n];
    rep(i, n) cin >> w[i];

    int sum[n+1];
    sum[0]=0;
    rep(i,n){
        sum[i+1]=sum[i]+w[i];
    }
    int ans=INF;
for(int i=1;i<n;i++){
    ans=min(ans,abs(sum[i]-(sum[n]-sum[i])));
}
cout<<ans<<endl;
    return 0;
}
