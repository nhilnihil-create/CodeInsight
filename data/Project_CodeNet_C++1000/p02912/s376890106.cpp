#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    priority_queue<ll> p;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        p.push(x);
    }
    for(int i=0;i<m;i++){
        ll x = p.top();
        p.pop();
        x /= 2;
        p.push(x);
    }
    ll ans = 0;
    while(!p.empty()){
        ans += p.top();
        p.pop();
    }
    cout<<ans<<"\n";
    return 0;

}


