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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    ll cc=max(c,d),dd=min(c,d),r=cc%dd;
    while(r>0){
        cc=dd;
        dd=r;
        r=cc%dd;
    }
    ans+=b/c+b/d-b/(c*d/dd);
    ans-=(a-1)/c+(a-1)/d-(a-1)/(c*d/dd);
    cout<<b-a+1-ans;
}