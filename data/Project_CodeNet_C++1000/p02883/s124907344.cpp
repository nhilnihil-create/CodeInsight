#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

typedef pair<ll,ll> Pair;
typedef set<ll> Set;
const ll max_s=1000010;
const ll MOD=1e9+7;

int main(){
    ll n,k;
    cin >> n >>k;
    ll a[n],f[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a,a+n,greater<ll>());
    sort(f,f+n);
    
    ll lb=-1, ub=1e12+1;
        
    while(ub-lb>1){
        ll mid=(lb+ub)/2;
        ll score=0;
        rep(i,n){
            ll at=a[i]-mid/f[i];
            if(at>0) score+=at;
        }
        if(score<=k){
            ub=mid;
        }
        else lb=mid;
    }
    kaku(ub);
}

