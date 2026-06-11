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
    ll l,r;cin>>l>>r;
    int ans = 10000;
    int f = 0;
    for (int i=l;i<=r;i++){
        for (int j=i+1;j<=r;j++){
            ans = min(ans,(i%2019)*(j%2019)%2019);
            if (i%2019==0 || j%2019==0){
                f = 1;
                break;
            }
        }
        if (f) break;
    }
    cout<<ans<<endl;
}