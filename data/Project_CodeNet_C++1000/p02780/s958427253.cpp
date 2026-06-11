#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;

double p[maxn];
double ans=0;
double sum[maxn+1];
int n,k;

int main(){
    cin >> n>>k;
    rep(i,n)cin >> p[i];

    rep(i,n){
        sum[i+1]=sum[i]+(double)(1+p[i])/2.0;
    }

    for(int i=1;i<=n-k+1;i++){
        ans=max(ans,sum[i+k-1]-sum[i-1]);
    }
    cout << fixed<<setprecision(10)<<ans<<endl;
    return 0;
}