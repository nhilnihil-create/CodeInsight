#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
long long GCD(long long a,long long b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll e=c/GCD(c,d)*d;
    ll x=b/c-(a-1)/c,y=b/d-(a-1)/d,z=b/e-(a-1)/e;
    cout<<b-a+1-(x+y-z);
}