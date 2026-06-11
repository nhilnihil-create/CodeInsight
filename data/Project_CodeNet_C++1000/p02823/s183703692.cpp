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
    ll n,a,b,ans;
    cin>>n>>a>>b;
    if((b-a)%2==0) ans=(b-a)/2;
    else if((b-a)%2==1) ans=min(a-1,n-b)+1+(b-a)/2;
    cout<<ans;
}