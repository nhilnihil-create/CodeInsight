#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
#define ms multiset
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    ll n,i,a,b;
    vt<ll> ai,bi;
    cin>>n;
    f(i,0,n,1){
        cin>>a>>b;
        ai.pb(a);
        bi.pb(b);
    }
    sort(ai.begin(),ai.end());
    sort(bi.begin(),bi.end());
    if (n&1)
        cout<<(bi[(n-1)/2]-ai[(n-1)/2]+1)<<endl;
    else{
        ld a=(ai[(n-2)/2]+ai[(n/2)])/(ld)2;
        ld b=(bi[(n-2)/2]+bi[(n/2)])/(ld)2;
        cout<<(ll)((b-a)*2+1)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}