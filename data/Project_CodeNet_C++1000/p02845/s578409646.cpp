#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const lli mod = 1e9+7;
lli n;

int main(void){
    cin >> n;
    vector<lli> a(n);
    rep(i, n){
        cin >> a[i];
    }
    vector<lli> x(n+1), y(n+1), z(n+1);
    rep(i, n){
        x[i+1] = x[i];
        y[i+1] = y[i];
        z[i+1] = z[i];
        if(a[i] == x[i]) x[i+1]++;
        else if(a[i] == y[i]) y[i+1]++;
        else if(a[i] == z[i]) z[i+1]++;
    }
    lli ans = 1;
    rep(i, n){
        lli t=0;
        if(a[i] == x[i]) t++;
        if(a[i] == y[i]) t++;
        if(a[i] == z[i]) t++;
        ans*=t;
        ans%=mod;
    }
    cout << ans << endl;

    return 0;
}
