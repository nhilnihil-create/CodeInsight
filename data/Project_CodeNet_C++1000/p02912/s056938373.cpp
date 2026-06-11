#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin>>n>>m;
    ll a[n];
    priority_queue<ll> pq;
    for (int i=0; i<n; i++){
        cin>>a[i];
        pq.push(a[i]);
    }
    ll cnt = 0;
    while(!pq.empty() && cnt<m){
        ll x = pq.top();
        pq.pop();
        x /= 2;
        if (x!=0)pq.push(x);
        cnt++;
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans<<endl;


}