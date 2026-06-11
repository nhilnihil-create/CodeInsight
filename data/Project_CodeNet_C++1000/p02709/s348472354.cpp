#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define MAX 10000007

int n;
vector<pii> v;

ll dp[2007][2007];

ll solve(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];


    ll atual = v[l+n-r-1].F;
    int idx = v[l+n-r-1].S;

    if(l==r){
        return atual*abs(idx-l);
    }

    ll a1 = solve(l+1, r) + atual*abs(idx-l);
    ll a2 = solve(l, r-1) + atual*abs(idx-r);

    return dp[l][r] = max(a1, a2);

}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

    memset(dp, -1, sizeof(dp));

	cin >> n;
    v.resize(n);
    FOR(i, n) cin >> v[i].F, v[i].S = i;

    sort(rall(v));


    cout << solve(0, n-1) << '\n';

	return 0;
}
