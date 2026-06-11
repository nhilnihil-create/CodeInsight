#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

ll lcm(ll x, ll y) { return x / __gcd(x, y) * y; }

ll solve(ll N,ll M,vector<ll> &a){
    ll num,ans;
    ans=0;
    num=1;
     while(a[0]%2==0){
        rep(i,N){
            if(a[i]%2!=0)return 0;
            a[i] /=2;
        }
        M /=2;
    }

    rep(i,N) if(a[i]%2==0) return 0;
    rep(i,N){
        num = lcm(num,a[i]);
        if(num>M) return 0;
    }

    return (M/num+1)/2;
}
int main(){
    ll N,M;
    ll num=1;
    cin >> N >> M;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
        a[i]/=2;
    }
    ll ans=solve(N,M,a);
    cout << ans << endl;
}