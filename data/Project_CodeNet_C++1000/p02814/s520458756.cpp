#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,m;
ll a[100001],b[100001];
int main(){
    cin>>n>>m;
    rep(i,n) cin>>a[i],b[i]=a[i];
    int pre=__builtin_ctz(b[0]);
    a[0]/=2;
    FOR(i,1,n){
        if(pre!=__builtin_ctz(b[i])){
            cout<<0<<endl;
            return 0;
        }
        a[i]/=2;
    }
    ll lcm=a[0];
    FOR(i,1,n){
        lcm=lcm*a[i]/__gcd(a[i],lcm);
        if(lcm>m){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<((m/lcm)+1)/2<<endl;
    return 0;
}