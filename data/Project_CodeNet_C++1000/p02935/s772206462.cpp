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
    double n; cin>>n;
    vector<double> v(n);
    rep(i,n) cin>>v[i];
    sort(all(v));
    double ans=v[0];
    repi(i,1,n) ans=(ans+v[i])/2;
    cout<<ans;
}