// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define nmax 200001
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define PI 3.141592654

int main() {
    
    ll n; cin>>n;

    map<ll,ll> vals;
    ll maxi = 0;
    for(int i=0;i<pow(2,n);i++) {
        ll a; scanf("%lld", &a);
        vals[a]++;
        maxi = max(maxi,a);
    }

    // for(auto i:vals)
    //     cout<<i.first<<" "<<i.second<<endl;

    if(vals[maxi]>1){
        cout<<"No"<<endl;
        return 0;
    }

    multiset<ll> se;
    se.insert(maxi);
    vals.erase(maxi);

    for(int i=1;i<=n;i++) {
        multiset<ll>::reverse_iterator rit = se.rbegin();
        vector<ll> temp;

        while(rit != se.rend()) {
            map<ll,ll>::iterator it = vals.lower_bound(*rit);
            if(it==vals.begin()) {
                cout<<"No"<<endl;
                return 0;
            }

            it--;
            temp.pb((*it).first);
            (*it).second--;
            
            if((*it).second==0)
                vals.erase((*it).first);

            rit++;
        }
        for(auto i:temp)
            se.insert(i);
    }

    if(se.size()!=pow(2,n) && vals.size()!=0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    return 0;
}

