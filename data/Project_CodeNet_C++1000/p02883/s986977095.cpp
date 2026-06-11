#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,b)  for(int i=0;i<(int)(b);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    cs
    int n;ll k,l=0,r=1e18;
    cin>>n>>k;
    vector<ll> v(n);
    vector<ll> vv(n);
    rep(i,n) cin>>v[i];
    rep(i,n) cin>>vv[i];
    sort(v.rbegin(),v.rend());
    sort(vv.begin(),vv.end());

    while(l<=r) {
        ll mid=(l+r)/2,dif=0;
        rep(i,n)
        if(v[i]*vv[i]>mid) 
        dif+=v[i]-mid/vv[i];

        if(dif<=k) r=mid-1;
        else l=mid+1;
    }
    cout<<l;

}