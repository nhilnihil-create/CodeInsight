#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo (1LL<<63-1)
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const long double Pi=acos(-1),e=2.718;
const int N=2e3+10, mod=1e9+7;
Matrix dp;
vector<pair<ll,ll> > a;
int n;

ll solve(int i,int l,int r){
    if(i==n)return 0;
    ll &ret=dp[i][l];
    if(ret+1)return ret;
    ret = max(solve(i+1,l+1,r)+a[i].F*abs(a[i].S-l),solve(i+1,l,r-1)+a[i].F*abs(a[i].S-r));
    return ret;
}

int main ()
{
    FASTIO
    cin >> n;
    a.resize(n);
    dp.resize(n,vector<ll>(n,-1));
    for(int i=0;i<n;i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a),greater<pair<ll,ll>>());
    cout << solve(0,0,n-1) << endl;
    return 0;
}
/**

*/
