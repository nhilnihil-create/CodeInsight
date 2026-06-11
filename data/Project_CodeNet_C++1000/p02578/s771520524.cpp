#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];

    ll ans=0;
    rep(i,1,n){
        ll diff=a[i-1]-a[i];
        if(diff>0){
            ans+=diff;
            a[i]+=diff;
        }
    }
    cout<<ans<<endl;
    return 0;
}