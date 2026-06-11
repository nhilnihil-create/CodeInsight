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
    int n;
    cin>>n;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    sort(all(l));
    ll ans=0;
    rep(i,n){
        repi(j,i+1,n){
            int k=l[i]+l[j];
            int x=lower_bound(l.begin(),l.end(),k)-l.begin();//k<=l[x]となるx
            ans+=x-j-1;
        }
    }
    cout<<ans;
}