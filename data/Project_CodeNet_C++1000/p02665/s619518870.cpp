#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll arr[n+1];
    ll sum=0;
    bool state=0;
    for(int i=0;i<=n;i++){
        cin>>arr[i];sum+=arr[i];
    }
    if(n==0){if(arr[0]==1){cout<<"1\n";return 0;}if(arr[0]==2){cout<<"-1\n";return 0;}}
    ll cnt=1,node=1;
    for(int i=1;i<=n;i++){
        node=min(node*2,sum);
        cnt+=node;
        node-=arr[i];
        sum-=arr[i];
        if(node<0)state=1;
    }
    if(state||arr[0]>0){cout<<"-1\n";return 0;}
    cout<<cnt<<"\n";
}
