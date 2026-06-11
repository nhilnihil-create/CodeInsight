#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

map<int,int> prime(ll n){
    map<int,int> ret;
    ret[1]++;;
    ll temp=n;
    for(ll i=2;i*i<=n;i++){
        while(temp%i==0){
            temp/=i;
            ret[i]++;
        }
    }
    if(temp!=1) ret[temp]++;
    return ret;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll r=gcd(a,b);
    map<int,int> mp=prime(r);
    int ans=0;
    for(auto x:mp) ans++;
    cout << ans << endl;  
}
