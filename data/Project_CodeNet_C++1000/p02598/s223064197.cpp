/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll a[n+1];
    ll l=1,r=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        r=max(r,a[i]);
    }
    //cout<<l<<" "<<r<<endl;
    while(l<=r){
        ll mid=(l+r)/2;
        ll cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=((a[i]-1)/mid);
        }
        //cout<<l<<" "<<r<<" "<<mid<<" "<<cnt<<endl;
        if(cnt<=k){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;

    return 0;
}


