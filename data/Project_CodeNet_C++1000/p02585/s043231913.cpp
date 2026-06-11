#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 1e6 + 10;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}
vector<ll>p(5100);
vector<ll>score(5100);
bool b[5100];
vector<ll>all;
void dfs(ll v,ll sum){
   if(b[v]==1) return;
   b[v] = 1;
   sum += score[p[v]];
   all.push_back(sum);
   dfs(p[v],sum);
}
void solve(){
    ll n,k;
    cin >> n >> k;
    ll ans = -1e18;
    for(ll i = 0;i<n;i++){
        cin >> p[i];p[i]--;
    }
    for(ll i = 0;i<n;i++) cin >> score[i];
    for(ll i = 0;i<n;i++){
        memset(b,0,sizeof(b));
        all.clear();
        dfs(i,0);
        ll q = k/all.size();
        ll rem = k%all.size();
        ll maxi = -1e18;
    if(q&&all.back()>0){
        for(ll j = 0;j<all.size();j++) maxi = max(maxi,all[j]);
        ans = max(all.back()*(q-1)+maxi,ans);
        maxi = 0;
        for(ll j = 0;j<rem;j++) maxi = max(maxi,all[j]);
        ans = max(ans,all.back()*q+maxi);
    }
    else{
        for(int i = 0;i<k;i++){
        if(i>=all.size()) break;
        ans = max(ans,all[i]);
    }
    }}
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}