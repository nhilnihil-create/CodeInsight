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
    ll N; cin >> N;
    vector<ll> A(N); rep(i,N) cin >> A[i];

    ll max_tall = 0;
    ll ans = 0;
    rep(i,N){
        max_tall = max(A[i], max_tall);
        ans += max(0, max_tall-A[i]);
    }

    cout << ans << endl;
}
