#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll count2(ll n){
    ll a=0;
    while(n%2==0){
        a++;
        n/=2;
    }
    return a;
}
int main(void){
    ll n,m,a[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]/=2;
    }
    ll count=count2(a[0]);
    bool zero=false;
    for(int i=1;i<n;i++){
        if(count!=count2(a[i])){
            zero=true;
            break;
        }
    }
    ll L=1;
    for(int i=0;i<n;i++){
        L=lcm(L,a[i]);
        if(L>m){
            zero=true;
            break;
        }
    }
    if(zero) cout<<0<<endl;
    else cout<<m/L-m/(2*L)<<endl;
}