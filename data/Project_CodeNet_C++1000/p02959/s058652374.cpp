#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a.at(i);
    vector<ll> b(n);
    rep(i,n) cin >> b.at(i);
    ll ans=0;
    rep(i,n){
        ll left=min(a.at(i),b.at(i));
        ans+=left;
        a.at(i)-=left;
        b.at(i)-=left;
        ll left2=min(a.at(i+1),b.at(i));
        ans+=left2;
        a.at(i+1)-=left2;
    }
    cout << ans << endl;
}
   
