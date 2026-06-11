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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

ll gcd(ll a,ll b){
    ll M=max(a,b);
    ll m=min(a,b);
    if(m==0){
        return M;
    }
    return gcd(m,M%m);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=b-a+1;
    ll cd=lcm(c,d);
    ans-=b/c-a/c;
    if(a%c==0) ans--;
    ans-=b/d-a/d;
    if(a%d==0) ans--;
    ans+=b/cd-a/cd;
    if(a%cd==0) ans++;
    cout<<ans<<endl;
    
}