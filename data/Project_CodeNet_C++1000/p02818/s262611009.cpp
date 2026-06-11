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
    ll a,b,k;
    cin>>a>>b>>k;
    if(a>=k) cout<<a-k<<" "<<b;
    else if(a<k&&k<=a+b) cout<<0<<" "<<b+a-k;
    else cout<<0<<" "<<0;
}