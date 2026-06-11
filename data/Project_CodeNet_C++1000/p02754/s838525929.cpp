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
    ll n,a,b;
    cin>>n>>a>>b;
    if(a==0){
        cout<<0; return 0;
    }
    if(n<=a+b){
        cout<<min(n,a); return 0;
    }
    ll ans=n/(a+b)*a+min(n%(a+b),a);
    cout<<ans;
}