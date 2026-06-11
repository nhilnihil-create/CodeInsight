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
    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    rep(i,n) cin>>a[i].second>>a[i].first;
    sort(all(a));
    ll sum=0;
    rep(i,n){
        sum+=a[i].second;
        if(sum>a[i].first){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}