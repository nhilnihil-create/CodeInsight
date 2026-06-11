#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;
const int MAX=10000;
ll fac[MAX],finv[MAX],inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
    COMinit();
    ll n,k;cin>>n>>k;
    for(int i=1;i<k+1;i++){
        ll a=COM(n-k+1,i);
        ll b=COM(k-1,i-1);
        ll ans=a*b;
        cout<<ans%MOD<<endl;
    }
}
