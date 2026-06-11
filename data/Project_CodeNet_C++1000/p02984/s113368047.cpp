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
    int n;cin>>n;
    vector<int> a(n);
    ll sum = 0;
    rep(i,0,n){
        cin>>a[i];
        sum += a[i];
    } 
    sum /= 2;
    for (int i=0;i<n-1;i+=2){
        sum-=a[i];
    }
    vector<ll> ans(n);
    ans[n-1] = sum*2;
    ans[0] = (a[n-1]-ans[n-1]/2)*2;
    rep(i,1,n-1){
        ans[i] = (a[i-1] - ans[i-1]/2)*2;
    }
    rep(i,0,n){
        cout<<ans[i]<<endl;
    }
}