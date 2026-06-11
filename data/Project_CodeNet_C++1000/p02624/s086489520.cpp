#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define lp(i,n) for(ll i = 0;i < ll(n);i++)
#define rlp(i,n) for(ll i = ll(n);i >= 0;i--)
#define rg(i,a,b) for(ll i = ll(a);i <= ll(b);i++)
#define wh(t) while(t)
#define re return
#define pb push_back
#define sz(s) (ll)(s.size())
#define fx(n) fixed<<setprecision(n)
#define NeverGiveUp ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
/*freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);*/
using namespace std;
/*ll mx = INT_MIN;
ll mn = INT_MAX;*/
/*ll xd,dx[4]={1,0,-1,0};
ll yd,dy[4]={0,1,0,-1};
bool valid(ll xd,ll yd,ll n,ll m){return xd>-1&&xd<n&&yd>-1&&yd<m;}*/
const int sz = 1e7+5;
const ll md = 1e9+7;
//ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
ll n,ans,a[sz];
int main()
{
    NeverGiveUp
    cin>>n;
    rg(i,1,n){
        for(ll j=0;j<=n;j+=i){
            a[j]++;
        }
    }
    rg(i,1,n){
        ans+=i*a[i];
    }
    cout<<ans;
    re 0;
}
