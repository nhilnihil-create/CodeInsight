#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;
struct Edge { int from, to; long long cost; };
using Graph = vector<vector<Edge>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    while(cin>>n>>k&&!(n==0&&k==0)){
        ll c_sum[n+1]={};
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            c_sum[i+1]=c_sum[i]+a;
        }
        ll ans=0;
        for(int i=k;i<=n;i++){
            ans=max(ans,c_sum[i]-c_sum[i-k]);
        }
        cout<<ans<<endl;
    }
}
