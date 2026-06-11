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
    ll a,b;
    cin>>a>>b;
    ll l=max(a,b),s=min(a,b),amari=l%s;
    while(amari!=0){
        l=s;
        s=amari;
        amari=l%s;
    }
    cout<<a/s*b;
}