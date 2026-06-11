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

vl eratos(ll n){
    vb isPrime(n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i = 2;i*i<=n;++i){
        if(isPrime[i]){
            for(ll j = i+i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    vl ret;
    rep(i,n+1){
        if(isPrime[i]) ret.push_back(i);
    }
    return ret;
}


int main(void) {
    vl primes = eratos(1000000);
    ll n;
    cin>>n;
    rep(i,primes.size()){
        if(primes[i] >= n){
            cout<<primes[i]<<endl;
            return 0;
        }
    }
	return 0;
}
