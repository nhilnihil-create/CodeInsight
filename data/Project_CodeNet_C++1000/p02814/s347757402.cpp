#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;

ll gcd(ll a,ll b) {
    if (a<b) swap(a,b);
    while (b>0) {
        ll tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

ll lcm(ll a,ll b) {
    ll c=gcd(a,b);
    ll d=a*b/c;
    return d;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]/=2;
    }
    bool flag=1;
    ll ans=a[0];
    int ele=1;
    while (a[0]%2==0) {
        a[0]/=2;
        ele*=2;
    }
    repr(i,1,n) {
        if (a[i]%ele==0 && (a[i]/ele)%2>0 && ans<=m) ans=lcm(ans,a[i]);
        else flag=0;
    }
    if (flag) cout << (m/ans+1)/2 << endl;
    else cout << 0 << endl;

    return 0;
}
