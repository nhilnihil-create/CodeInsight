#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll cnt[100010];


// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    ll ma=0;
    ll d[n];
    rep(i,n){
        cin>>d[i];
        ma=max(ma,d[i]);
        cnt[d[i]]++;
    }

    if(cnt[0]!=1 || d[0]!=0){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1;
    
    for(int i=1;i<=ma;i++){
        ans=(ans*modpow(cnt[i-1],cnt[i],998244353))%998244353;
    }
    cout<<ans%998244353<<endl;
}
