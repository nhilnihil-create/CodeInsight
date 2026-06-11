#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
ll loop(ll h){
    if(h==1) return 1;
    ll x=2*loop(h/2)+1;
    return x;
}
int main() {
    ll h,cnt; cin>>h;
    cnt=loop(h);
    cout<<cnt;
}