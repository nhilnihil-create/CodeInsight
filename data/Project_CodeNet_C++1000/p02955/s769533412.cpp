#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,sum,a[505];
bool chk(ll x){
    vector<ll> v;
    for(ll i=1;i<=n;i++)v.push_back(a[i]%x);
    sort(v.begin(),v.end());
    ll rem=0,reqd=0,l=0,r=v.size()-1;
    while(l<=r){
        if(rem<=0){
            rem+=v[l];
            reqd+=v[l];
            l++;
        }
        else{
            rem-=(x-v[r]);
            reqd+=(x-v[r]);
            r--;
        }
    }
    if(reqd>2*k || rem!=0)return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    ll ans=1;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i)continue;
        if(chk(i))ans=max(ans,i);
        if(chk(sum/i))ans=max(ans,sum/i);
    }
    cout<<ans;
}