#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAX(ll a,ll b){
    if(a>b) return a;
    return b;
}
int main(void){
    ll n,k;
    cin>>n>>k;
    ll a[200000],f[200000];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&f[i]);
    sort(a,a+n,greater<ll>());
    sort(f,f+n);
    ll left=-1,right=100000000000000;
    while(right-left>1){
        ll mid=(left+right)/2;
        ll count=0;
        for(int i=0;i<n;i++){
            count+=MAX(0,a[i]-mid/f[i]);
        }
        if(count<=k) right=mid;
        else left=mid;
    }
    cout<<right<<endl;
}
