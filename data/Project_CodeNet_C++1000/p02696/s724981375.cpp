#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll ans1=(a*n)/b-a*(n/b),ans2=(a*(b-1))/b-a*((b-1)/n);
    cout<<max(ans1,ans2);
}