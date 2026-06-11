#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> w(n);
    rep(i,0,n) cin>>w[i];
    int ans = 10000000;
    rep(i,0,n){
        int a = 0, b= 0;
        rep(j,0,i) a+=w[j];
        rep(j,i,n) b+=w[j];
        ans = min(ans,abs(a-b));
    }
    cout<<ans<<endl;
}