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
    int n,k;
    cin>>n>>k;
    vector<ld> p(n+1),a(n+1);
    ld ans=0;
    repi(i,1,n+1){
        cin>>p[i];
        a[i]=((1+p[i])*p[i]/2)/p[i]+a[i-1];
    }
    repi(i,k,n+1){
        ans=max(ans,a[i]-a[i-k]);
    }
    cout<<fixed<<setprecision(9)<<ans;
}