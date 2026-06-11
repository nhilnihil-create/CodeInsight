#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int maxsize = 300000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> plus(maxsize),minus(maxsize);
    REP(i,n){
        cin >> a[i];
        if(i+a[i]<maxsize)plus[i+a[i]]++;
        if(i-a[i]>=0) minus[i-a[i]]++;
    }
    ll ans = 0;
    REP(i,maxsize-1){
        ans+=plus[i]*minus[i];
    }
    cout << ans << endl;
}