#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<ll> a(n),b(n),c(n);
    rep(i,0,n){
        cin>>a[i];
    }
    b[0] = a[0]; c[n-1] = a[n-1];
    rep(i,1,n) b[i] = max(b[i-1],a[i]);
    repp(i,n-2,0) c[i] = max(c[i+1],a[i]);
    rep(i,0,n){
        if (i==0){
            cout<<c[1]<<endl;
            continue;
        }
        if (i==n-1){
            cout<<b[n-2]<<endl;
            continue;
        }
        cout<<max(b[i-1],c[i+1])<<endl;
    }
}