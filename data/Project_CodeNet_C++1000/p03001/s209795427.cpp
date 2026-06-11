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
    ld w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(9)<<w*h/2;
    if(x==w/2&&y==h/2) cout<<" "<<1;
    else cout<<" "<<0;
}