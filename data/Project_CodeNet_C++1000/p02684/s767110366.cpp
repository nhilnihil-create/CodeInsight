
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    vector<ll> vis(n+1);
    ll cur=1;
    ll cnt =1;
    while(vis[cur]==0){
        vis[cur] = cnt++;
        cur = arr[cur];
    }
    ll cur2=cur;
    vector<ll> loop;
    do{
        loop.push_back(cur2);
        cur2 = arr[cur2];
    }while(cur2!=cur);
    ll dist = vis[cur]-1;
    if(k<dist){
        cur=1;
        while(k--)
            cur = arr[cur];
        cout<<cur<<endl;
    }
    else 
        cout<<loop[(k-dist)%loop.size()]<<endl;
    
    return 0;
}

