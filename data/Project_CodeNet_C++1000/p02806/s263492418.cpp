#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
typedef vector<int> vi;
typedef vector<ll> vl;
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t%mod;
    }
    return n*rep_jijo(n,x-1)%mod;
}
ll com(ll n,ll r){
    ll x=1,y=1;
    ll tmp=n;
    while(tmp>=n-r+1){
        x=x*tmp%mod;
        tmp--;
    }
    while(r>0){
        y=y*r%mod;
        r--;
    }
    return x*rep_jijo(y,mod-2)%mod;
}

int main (){
    int n;
    cin >> n;
    vector<string>s(n);
    vi t(n);
    int sum=0;
    rep(i,n) {
        cin >> s[i] >> t[i];
        sum+=t[i];
    }
    string x;
    cin >> x;
    rep(i,n){
        sum-=t[i];
        if(s[i]==x) break;
    }
    cout << sum << endl;


    

    return 0;
}
