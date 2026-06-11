#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define rep(i, n) \
for(int i = 0; i <n; i++)
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63

void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n);
    rep(i,n) cin>>nums[i];
    sort(nums.begin(), nums.end());
    ll ans = 0;
    rep(i,n-1){
        ans+=nums[n-1-(i+1)/2];
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
