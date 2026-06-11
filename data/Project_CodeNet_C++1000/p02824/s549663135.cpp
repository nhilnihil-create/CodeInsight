
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
#define ll long long
const int N = 1e5 +5;
ll a[N];
ll b[N];
bool ok(ll x,ll m,ll v,ll p,ll n){

    memcpy(b,a,sizeof a);
    for(int i = x;i <= n;++i){
        if(!v) break;
        b[i] += m;
        v --;
    }
    for(int i = 1;i <= p-1;++i){
        if(!v) break;
        b[i] += m;
        v --;
    }
    ll d = v * m;
    if(d == 0){
        return b[x] >= b[p];
    }
    else{
        for(int i = p;i < x;++i){
            if(b[i] - b[x] > 0) return 0;
            ll po = b[x] - b[i];
            po = min(po,m);
            d -= po;
            if(d <= 0) break;
        }
        if(d > 0) return 0;
        return 1;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	ll n,m,v,p;
	cin >> n >> m >> v>>p;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
    sort(a + 1,a + n + 1,greater<ll>());
    int l = p ,r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(ok(mid,m,v,p,n)) l = mid;
        else r = mid - 1;
    }
    cout<<l;
			
    return 0;


}
