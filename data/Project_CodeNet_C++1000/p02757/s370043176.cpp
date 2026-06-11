#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
#define all(v) v.begin(),v.end()

int p;

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
        return t*t%p;
    }
    return n*rep_jijo(n,x-1)%p;
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
int main(){
    int n;
    ll ans=0;
    string s;
    cin >> n >> p >> s;
    if(p==2){
        rep(i,n){
            int x=s[i]-'0';
            if(x%2==0) ans+=i+1;
        }
        cout << ans << endl;
    }
    else if(p==5){
        rep(i,n){
            int x=s[i]-'0';
            if(x%5==0) ans+=i+1;
        }
        cout << ans << endl;
    }
    else{
        reverse(all(s));
        vector<ll>a(n);
        rep(i,n) a[i]=(s[i]-'0')*rep_jijo(10,i)%p;
        vector<ll>rui(n+1);
        rep(i,n+1){
            if(i==0) rui[i]=0;
            else rui[i]=(rui[i-1]+a[i-1])%p;
        }
        map<ll,ll>mp;
        rep(i,n+1) mp[rui[i]]++;
        for(auto p:mp){
            ans+=p.second*(p.second-1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}
