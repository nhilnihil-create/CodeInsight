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
    ll n,k;cin>>n>>k;
    ll r,s,p;cin>>r>>s>>p;
    string t;cin>>t;
    bool state[n];mset(state);
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(i<k){
            if(t[i]=='r')cnt+=p;
            if(t[i]=='p')cnt+=s;
            if(t[i]=='s')cnt+=r;
            state[i]=true;
            continue;
        }
        if(!state[i-k]||t[i]!=t[i-k]){
            if(t[i]=='r')cnt+=p;
            if(t[i]=='p')cnt+=s;
            if(t[i]=='s')cnt+=r;
            state[i]=true;
            continue;
        }
    }
    cout<<cnt<<"\n";
}
