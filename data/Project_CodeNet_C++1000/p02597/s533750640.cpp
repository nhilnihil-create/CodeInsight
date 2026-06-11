#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define rep(i,a,b) for(ll i = a;i <= b;i++)
#define repv(i,a,b) for(ll i = a;i >= b;i--)
#define e endl
#define all(v) v.begin(), v.end()
typedef pair<ll,ll> pp;

int lcm(int a, int b)
{
    int lar = max(a, b);
    int small = min(a, b);
    for (int i = lar; ; i += lar) {
        if (i % small == 0)
            return i;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return (a.second < b.second);
}

ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1;     // Initialize result
  
    x = x % p; // Update x if it is more than or
                // equal to p
   
    if (x == 0) return 0; // In case x is divisible by p;
  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
  
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

bool isPowerOfTwo (ll x)
{
    return x && (!(x&(x-1)));
} //cout << h[i] << " " << cnt[i] << " " << good[i] << " " << bad[i] << e;


void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll r = 0;
    for(ll i = 0;i < s.length();i++) if(s[i] == 'R') r++;
    ll count = 0;
    for(ll i = 0;i < r;i++){
        if(s[i] == 'W') count++;
    }
    cout << count << endl;
}
        
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //ll t; cin >> t; while(t--)
        solve();
}
