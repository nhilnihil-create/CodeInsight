#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define speed ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    speed;
    ll n,k; cin>>n>>k;
    ll p[n];    for(auto &i:p)   cin>>i;
    sort(p,p+n);  ll sum=0;
    for(ll i=0;i<k;i++){
        sum+=p[i];
    }
    cout<<sum<<'\n';
    return 0;
}