#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
   string s,t;
   cin >> s >> t;
   vector< vector<int> >pos(26);
   for(int i = 0;i<s.size();i++){
    pos[s[i]-'a'].push_back(i+1);
   }
   int now = 0;
   ll ans = 0;
   for(int i = 0;i<t.size();i++){
    if(pos[t[i]-'a'].size()==0) {cout << -1;return;}
    auto p = upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),now);
    if(p!=pos[t[i]-'a'].end()){
        ans += (*p-now);
        now = *p;
    }
    else{
        p = pos[t[i]-'a'].begin();
        ans += s.size()-now+*p;
        now = *p;
    }
   }
   cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}