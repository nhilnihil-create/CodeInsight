#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5,mod=1e9+7;
ll d[5005];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll k,q;cin>>k>>q;
    for(ll i=0;i<k;i++)cin>>d[i];
    for(ll n,x,m;q>0;q--){
        cin>>n>>x>>m;
        x%=m;
        ll zeroes=0,sum=x;
        for(ll i=0;i<k;i++){
            ll val = d[i]%m;
            ll cnt = (n-1)/k;
            if((n-1)%k>i)cnt++;
            if(val==0)zeroes+=cnt;
            else sum+=cnt*val;
        }
        ll ans = sum/m - x/m + zeroes;
        cout<<(n-1)-ans<<"\n";
    }
}