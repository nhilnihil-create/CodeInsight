#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
ll gcd(ll a,ll b){
    ll m = min(a,b);
    ll M = max(a,b);
    if(M%m==0){
        return m;
    }else{
        return gcd(m,M%m);
    }
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans=b-a+1;
    ans -= b/c-(a-1)/c;
    ans -= b/d-(a-1)/d;
    ll e = lcm(c,d);
    ans += b/e-(a-1)/e;
    cout<<ans<<endl;

    

  return 0;
}