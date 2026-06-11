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

map<ll,ll> primefact(ll n){
    ll a = 2;
    map<ll,ll> ret;
    if(n == 1) return ret;
    while(a*a <= n){
        if(n%a == 0){
            n /= a;
            ret[a]++;
        }
        else{
            a++;
        }
    }
    ret[n]++;
    return ret;
}


int main(void) {
    ll n;
    cin>>n;
    map<ll,ll> pitsu = primefact(n);
    ll ans = 0;
    for(pair<ll,ll> ngo:pitsu){
        ll i = 1;
        ll ngoo = 0;
        while(ngo.second-(i+ngoo) > 0){
            ngoo += i;
            i++;
        }
        if(ngo.second-(i+ngoo) == 0) ans += i;
        else ans += (i-1);
    }
    cout<<ans<<endl;
	return 0;
}
