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
    ll n,ans=1;
    cin>>n;
    for(ll i=1;i*i<=n;i++){
            if(n%i==0) ans=max(i,ans);
    }
    cout<<n/ans+ans-2;
}