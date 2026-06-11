#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,sum=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll part=0,mini=sum;
    rep(i,n){
        part+=a[i];
        mini=min(mini,abs(part-(sum-part)));
    }
    cout<<mini;
}