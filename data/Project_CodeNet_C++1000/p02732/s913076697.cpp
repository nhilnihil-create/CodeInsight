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
    int n;
    cin>>n;
    vector<ll> a(n),b(n+1);
    rep(i,n){
        cin>>a[i];
        b[a[i]]++;
    }
    ll sum=0;
    rep(i,n+1)
        if(b[i]>=2) sum+=b[i]*(b[i]-1)/2;
    rep(i,n){
        if(b[a[i]]<2) cout<<sum<<endl;
        else cout<<sum-(b[a[i]]-1)<<endl;
    }
}