#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> vec(n);
    rep(i,n) cin >> vec[i];
    ll count=0;
    ll x=vec[0];
    while(x%2==0){
        count++;
        x/=2;
    }
    ll y=pow(2,count);
    rep(i,n){
        if(vec[i]%y==0&&vec[i]%(y*2)!=0){
            vec[i]/=2;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans=1;
    rep(i,n){
        ans=lcm(ans,vec[i]);
        if(ans>10000000000){
        cout << 0 << endl;
        return 0;
        }
    }
    ll fans=0;
    if(m>=ans)fans=(m-ans)/(2*ans)+1;
    cout << fans << endl;
}