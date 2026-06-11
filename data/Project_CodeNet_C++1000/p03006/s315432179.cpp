#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
vector<pair<ll, ll>> vp;

struct union_find {
	ll par[MAX_N];
	ll Size[MAX_N];
	union_find(ll n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
			Size[i] = 1;
		}
	}
	ll root(ll x) {
		if (par[x] == x)return x;
		return par[x] = root(par[x]);
	}
	bool same(ll x, ll y) {
		return root(x) == root(y);
	}
	void unite(ll x, ll y) {
		if (same(x, y))return;
        if(Size[root(x)] < Size[root(y)]) swap(x, y);
		Size[root(x)] += Size[root(y)];
		par[root(y)] = root(x);
	}
};

int main(){
    ll n;
    cin>>n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    ll ans=INF;
    vp.resize(n);
    for(ll i=0;i<n;i++) cin>>vp[i].first>>vp[i].second;
    sort(vp.begin(), vp.end());
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            pair<ll, ll> p=make_pair(vp[j].first-vp[i].first,vp[j].second-vp[i].second);
            struct union_find U(n);
            for(ll k=0;k<n-1;k++){
                for(ll m=k+1;m<n;m++){
                    if(p.first==vp[m].first-vp[k].first && p.second==vp[m].second-vp[k].second){
                        U.unite(m,k);
                    }
                }
            }
            vector<bool> used(n,0);
            ll sub=0;
            for(int k=0;k<n;k++){
                if(!used[U.root(k)]){
                    used[U.root(k)]=true;
                    sub+=1;
                }      
            }
            ans=min(ans,sub);
        }
    }
    cout<<ans<<endl;
}
