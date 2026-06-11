#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repm(i,m,n) for(ll i=m;i<n;i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define YesNo(a) (a)?cout<<"Yes"<<endl:cout<<"No"<<endl
#define YESNO(a) (a)?cout<<"YES"<<endl:cout<<"NO"<<endl
#define INF (2e9)
#define PI (acos(-1))
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007

typedef long long ll;

int main(){
    ll X; cin >> X;
    ll K; cin >> K;
    ll D; cin >> D;

    X = max(X, -X);
    
    ll ans = X;
    if(X / D >= K) ans -= D*K;
    else{
        ans = X % D;
        ll tmp_K = K - X/D;
        if(tmp_K%2) ans -= D;
    }

    ans = max(ans, -ans);

    cout << ans << endl;
}
