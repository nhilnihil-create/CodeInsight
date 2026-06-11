#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
ll a[100005];
ll ans;
int main(void){
    cin>>n>>m;
    priority_queue<ll,vector<ll>,less<ll>> q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    for(int i=0;i<m;i++){
        ll t=q.top();
        q.pop();
        t=t/2;
        q.push(t);
    }
    for(int i=0;i<n;i++){
        ll k=q.top();
        q.pop();
        ans+=k;
    }
    cout<<ans<<endl;

}
