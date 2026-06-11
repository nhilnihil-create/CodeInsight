#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define f(i,l,h) for(ll i=l;i<h;i++)
#define fr(i,h,l) for(ll i=h;i>=l;i--)

using namespace std;

typedef pair<ll,ll> pll;
const ll INF=(ll)(1e9+7);
typedef vector<ll> vll;

int main()
{
    //cout << "Hello world!" << endl;
    ll n;
    cin>>n;
    ll a[n+1];
    f(i,0,n+1) cin>>a[i];
    if(n==0){
        if(a[0]==1) cout<<"1"<<endl;
        else cout<<"-1"<<endl;
        return 0;
    }
    ll leaf[n+1];
    leaf[n]=a[n];
    for(ll i=n-1;i>=0;i--){
        leaf[i]=a[i]+leaf[i+1];
    }
    ll ans=1;
    bool flag=true;
    ll lvl[n+1];
    lvl[0]=1;
    for(ll i=1;i<=n;i++){
        lvl[i]=min(2*(lvl[i-1] - a[i-1]),leaf[i]);
        if(lvl[i]<a[i]){
            flag=false;
            break;
        }
        ans+=lvl[i];
    }

    if(!flag){
        ans=-1;
    }

    cout<<ans<<endl;
}
