#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    vec P(n+1),C(n+1);
    rep1(i,n) cin>>P[i];
    rep1(i,n) cin>>C[i];
    ll ans=-1e18;
    rep1(i,n){
        vec num(n+1,0);
        ll a=i,b=0;
        ll s=0;
        while(num[P[a]]==0){
            num[P[a]]=1;
            s+=C[P[a]];
            a=P[a];
            b++;
        }
        if(b<k){
            if(s>0){
                ll x=-1e18,y=0,a=i;
                rep(j,b+k%b){
                    y+=C[P[a]];
                    a=P[a];
                    x=max(x,y);
                }
                ans=max(ans,(k/b-1)*s+x);
            }
            else{
                ll x=-1e18,y=0,a=i;
                rep(j,b){
                    y+=C[P[a]];
                    a=P[a];
                    x=max(x,y);
                }
                ans=max(ans,x);
            }
        }
        else{
            ll x=-1e18,y=0,a=i;
            rep(j,k){
                y+=C[P[a]];
                a=P[a];
                x=max(x,y);
            }
            ans=max(ans,x);
        }
    }
    cout<<ans;
}