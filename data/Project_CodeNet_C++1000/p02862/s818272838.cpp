#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll fac[2000007],finv[2000007],inv[2000007];
void cominit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<2000007;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll com(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cominit();
    ll x, y;
    cin >> x >> y;
    if(x > y * 2 || y > x * 2 || (x + y) % 3){
    	cout << 0 << endl;
    	return 0;
    }
    if(x > y){
    	swap(x, y);
    }
    ll le = 0, ri = 1000000000LL, mid;
    while(ri - le > 1LL){
    	mid = (le + ri) / 2LL;
    	if(y - mid * 2LL >= x - mid) le = mid;
    	else ri = mid;
    }
    ll num = x - le;
    num /= 3LL;
    cout << com(le + num * 2, num) << endl;
    return 0;
}
