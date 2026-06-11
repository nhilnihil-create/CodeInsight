#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,a,n) for(int i=a;i>=n;i--)
#define INF 2000000000
#define pb(a) push_back(a)

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef vector<pii> VP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];

    vector<int> dp(100001);
    rep(i,0,n+1) dp[i] = INF;

    rep(i,0,n) *lower_bound(dp.begin(), dp.begin() + n, a[i]) = a[i];

    cout << lower_bound(dp.begin(), dp.begin() + n, INF) - dp.begin() << endl;
    return 0;
}