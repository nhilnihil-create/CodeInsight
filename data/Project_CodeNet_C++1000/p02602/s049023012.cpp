#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000000,mod=1000000007,BS,k;
#define en printf("\n");

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
    ll n,k;cin>>n>>k;ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    for(ll i=k;i<n;i++){
    if(arr[i-k]<arr[i])
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;}
}
