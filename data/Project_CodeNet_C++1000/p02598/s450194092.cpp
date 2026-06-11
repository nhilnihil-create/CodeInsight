#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

ll n,k;
double a[200010];

bool check(double x){
    ll count=0;
    for(int i=0;i<n;i++){
        count+=max(ll(0),ll(ceil(a[i]/x)-1));
    }
    if(count<=k) return true;
    return false;
}

double solve(){
    double low=0,high=1e9+1;
    for(int i=0;i<100;i++){
        double mid=(low+high)/2;
        if(check(mid)) high=mid;
        else low=mid;
    }
    return high;
}

int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=ceil(solve());
    cout<<ans<<endl;
}