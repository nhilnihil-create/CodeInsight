#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a,ll n,ll m=MOD){
    ll p=1;
    for(;n;n>>=1,a=a*a%m)
        if(n&1)
            p=p*a%m;
    return p;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll answer = modpow(2,n);
    ll nca=1,ncb=1;
    ll tmp =n;
    REP(i,a){
        nca=nca*tmp%MOD;
        tmp--;
        nca=nca*modinv(i+1,MOD)%MOD;
    }
    tmp = n;
    REP(i,b){
        ncb=ncb*tmp%MOD;
        tmp--;
        ncb=ncb*modinv(i+1,MOD)%MOD;
    }
    answer -= nca;
    answer -= ncb;
    answer -= 1;
    while(answer < 0)answer+=MOD;
    cout << answer << endl;
    return 0;
}