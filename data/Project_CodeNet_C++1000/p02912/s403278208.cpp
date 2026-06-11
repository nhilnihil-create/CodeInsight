#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m;cin>>n>>m;
    priority_queue<ll>q;
    for(int i=0;i<n;i++){
        ll d;cin>>d;
        q.push(d);
    }
    while(m--){
        ll a=q.top();
        q.pop();
        q.push(a/2);
    }
    ll sum=0;
    while(q.size()){
        sum+=q.top();
        q.pop();
    }
    cout<<sum<<"\n";
}
