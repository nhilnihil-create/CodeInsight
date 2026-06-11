#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);
ll solve(){
    int n;
    cin>>n;
    int a[n];
    for(int &i:a) cin>>i;
    sort(a,a+n);
    ll ans=0;
    priority_queue<ll> pq;
    pq.push(a[n-1]);
    for(int i=n-2;i>=0;i--){
        ans+=pq.top();
        pq.pop();
        pq.push(a[i]);
        pq.push(a[i]);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
