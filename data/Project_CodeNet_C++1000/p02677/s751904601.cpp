#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using ld=long double;

int main() {
    ld a,b,h,m;
    cin>>a>>b>>h>>m;
    ld rad=2*M_PI*((h/12)+((m/60)/12)-(m/60));
    ld ans2=ld(pow(a,2))+ld(pow(b,2))-ld(2*a*b)*cosl(rad);
    cout<<fixed<<setprecision(15)<<sqrtl(ans2);
    return 0;
}