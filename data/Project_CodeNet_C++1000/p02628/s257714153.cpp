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
    int n, k; cin >> n >> k;
    vector<int> p(n); rep(i,n) cin >> p[i];

    sort(all(p));

    int ans = 0;
    rep(i,k){
        ans += p[i];
    }

    cout << ans << endl;
}