#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll arr[n+1];
    unordered_map<ll,ll> count;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        count[arr[i]+i]++;
    }

    ll ans=0;
    for(ll i=1; i<=n; i++){
        if(count.find(i-arr[i])!=count.end()){
            ans+=count[i-arr[i]];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
