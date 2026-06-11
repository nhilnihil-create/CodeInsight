#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    priority_queue<ll> q;
    int n, m; cin>>n>>m;
    ll x, ans = 0;
    for(int i = 0; i<n; i++){
        cin>>x;
        q.push(x);
    }

    for(int i = 0; i<m; i++){
        x = q.top();
        q.pop();
        q.push(x/2);
    }

    while(!q.empty()){
        ans += q.top();
        q.pop();
    }
    cout<<ans<<"\n";
    return 0; 
}
