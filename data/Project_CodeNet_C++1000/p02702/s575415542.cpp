#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  ff         first
#define  ss         second
#define  pb         push_back
#define  all(x)     (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  deb(x)     cout << #x << " - " << x << "\n";
#define  IOS        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)      cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]\n"; 
#define  D2p(x)	    cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << "\n";
#define  ps(x,y)    fixed<<setprecision(y)<<x
 
#define PI 3.141592653589793238462643383279502884L
// const ll MOD = 1e9 + 7;
const ll INF = 1000000000;
const ll MAX_N = 4e4 + 10;

 
int main() {
    IOS;
    ll MOD = 2019;
    string s; cin >> s;
    map<ll,ll>mp;
    ll suf = 0,pot = 1;
    mp[suf]++;
    ll ans = 0;
    for(ll i=s.size()-1;i>=0;--i){
        ll dig = s[i] - '0';
        suf = (suf + dig * pot) % MOD;
        pot = (10 * pot) % MOD;
        ans += mp[suf];
        mp[suf]++;
    }
    cout << ans;
}