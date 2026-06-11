#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define PII pair<ll,ll>

const ll sz=1e5+100;
vector<ll> ad[sz];

int main()
{
    ll n,m,i,j,k,p,x,y;

    cin>>n>>m;
    for(i=0;i<n;i++) {
        cin>>x>>y;
        ad[x-1].push_back(y);
    }
    priority_queue<ll> pq;

    ll ans=0;
    for(i=m;i>=1;i--){
        ll siz=ad[m-i].size();
        for(j=0;j<siz;j++) pq.push(ad[m-i][j]);
        if(pq.size()==0) continue;
        ll x=pq.top();
        pq.pop();
        ans+=x;
    }

    cout<<ans<<'\n';
}
