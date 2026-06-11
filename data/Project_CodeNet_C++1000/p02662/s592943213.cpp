#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo 1e18
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vs vector<string>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const long double Pi=acos(-1),e=2.718;
const int N=3e3+10,mod=998244353;
Matrix dp;
vll a;
ll n,k;
ll solve(int i,int sum){
    if(i==n)return (k==sum);
    if(sum > k)return 0;
    ll &ret = dp[i][sum];
    if(ret+1)return ret;
    ret = solve(i+1,sum+a[i]) + 2*solve(i+1,sum);
    ret %= mod;
    return ret;
}
int main ()
{
    FASTIO;
    cin >> n >> k;
    a.resize(n);
    dp.assign(N,vll(N,-1));
    for(auto &x:a)cin >> x;
    cout << solve(0,0) << endl;
    return 0;
}
/**


*/
