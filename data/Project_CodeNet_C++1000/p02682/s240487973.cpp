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
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    if(k<=a) cout<<k;
    else if(a<k&&k<=a+b) cout<<a;
    else if(a+b<k) cout<<a-(k-(a+b));
}