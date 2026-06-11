#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int MAXN=1e5+100;;
ll n,m;
ll a[MAXN];
ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
int main()
{
    ios;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]/=2;
    ll c=1,f=0;
    for(int i=1;i<=n;i++) c=lcm(c,a[i]);
    if(c>m) f=1;
    for(int i=1;i<=n;i++){
        if((c/a[i])%2==0){
            f=1;
            break;
        }
    }
    if(f){
        cout<<0<<'\n';
        return 0;
    }
    ll tmp=m/c;
    ll ans=tmp/2;
    if(tmp&1) ans++;
    cout<<ans<<'\n';
    return 0;
}