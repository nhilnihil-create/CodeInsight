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
    ld a,b,x;
    cin>>a>>b>>x;
    ld ans;
    if(a*a*b<=2*x) ans=atan(2*(a*a*b-x)/(a*a*a));
    else ans=atan((b*b*a)/(2*x));
    ans=ans*180/PI;
    cout<<fixed<<setprecision(10)<<ans;
}