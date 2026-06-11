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

ll n,cnt;
vector<queue<ll>>v(1005);
bool vst[1005];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    ll d;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-1;j++){
            cin>>d;v[i].push(d);
        }
    }
    ll cnt=0,ans=0;
    vi a;
    for(int i=1;i<=n;i++)a.pb(i);
    while(true){
        vi b;
        bool state=1;
        for(auto i:a){
            if(v[i].empty()||vst[i])continue;
            vst[i]=true;
            ll val=v[i].front();
            if(vst[val])continue;
            if(v[val].front()==i){
                state=0;vst[val]=true;v[val].pop();v[i].pop();cnt++;b.pb(i);b.pb(val);
            }
        }
        ans++;mset(vst);a=b;b.clear();
        if(state)break;
    }
    if(cnt<(n*(n-1))/2)cout<<"-1\n";
    else cout<<ans-1<<"\n";
}

