//#define _GLIBCXX_DEBUG
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
    int ans = 1;
    int n;cin>>n;
    vector<pair<ll,ll>> a(n);
    rep(i,0,n){
        int x,y;cin>>x>>y;
        a[i] = mp(y,x);
    }
    sort(a.begin(),a.end());
    ll num = 0;
    rep(i,0,n){
        num += a[i].second;
        if (num>a[i].first){
            ans = 0;
            break;
        }
    }
    if (ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}