#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
//#define mod 1000000007
#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT {
	__INIT() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(15);
	}
}__init;

ll n,x,y;

ll dist(ll a,ll b){
    if(x <= a && b <= y){
        return min(b-a,y-x+1-(b-a));
    }
    else if(x <= a && a<=y){
        return min(b-a,b-y+y-x+1-(y-a));
    }
    else if(x <= b && b <= y){
        return min(b-a,x-a+y-x+1-(b-x));
    }
    else{
        if(b < x) return b-a;
        if(a > y) return b-a;
        return b-a-(y-x)+1;
    }
}

int main(void) {
    cin>>n>>x>>y;
    vl dis(n-1,0);
    ll cnt = 0;
    for(ll i = 1;i<=n;i++){
        for(ll j = i+1;j<=n;j++){
            //cout<<i<<" "<<j<<" "<<"d:"<<dist(i,j)<<endl;
            dis[dist(i,j)-1]++;
            cnt++;
        }
    }
    rep(i,n-1){
        cout<<dis[i]<<endl;
    }
	return 0;
}
