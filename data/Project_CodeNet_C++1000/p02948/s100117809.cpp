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

bool comp(ii a,ii b){
    if(a.fi!=b.fi)return a.fi<b.fi;
    return a.se>b.se;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m;cin>>n>>m;
    deque<ii>v;
    for(int i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(all(v),comp);
    //for(auto x:v)cout<<x.fi<<" "<<x.se<<"\n";
    priority_queue<ll>q;
    ll sum=0;
    for(int i=1;i<=m;i++){
        while(v[0].fi==i){
            q.push(v[0].se);
            v.pop_front();
        }
        if(q.size()){
            sum+=q.top();
            q.pop();
        }
    }
    cout<<sum<<"\n";
}
