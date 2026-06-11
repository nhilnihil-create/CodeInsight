#include <bits/stdc++.h>

// definitions
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, l, r) for (long long i = (l); i < (long long)(r); i++)
#define repb(i, r, l) for (long long i = (r); i > (long long)(l); i--)
#define high(x) __builtin_popcountll(x)
#define pb push_back
#define pf push_front
#define mod1 998244353
#define mod 1000000007
#define MAX_CHAR 256
#define pi 3.1415926535897932384



using namespace std;
typedef vector<long long> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector< pair<long long, long long> > vp;
typedef vector<tuple<long long , long long , long long> > vtup;
typedef deque <long long> dql;
typedef deque <char> dqc;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll INF=1e18;



// prevent collisions in unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

template <class T>
void read(T arr[],ll n) {rep(i,0,n) cin>> arr[i];}

typedef unordered_map <long long, long long, custom_hash> umap;


// standard functions
ll mystoi(string str)
{
    stringstream ss(str);
    ll ans=0;
    ss >> ans;

    return ans;
}

ll exp(ll x, ll ex, ll p) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x)%p;
        ex >>= 1ll;
        x = (x * x)%p;
    }
    return ans;
}

bool sort_cond(const pair<ll,ll> &a, const pair <ll,ll> &b)
{
    return ((a.f-a.s)>(b.f-b.s));
}
  

// code beigns in main
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
    // cin >> t;
    while(t--)
    {
        ll h1,m1,h2,m2,k;
        cin >> h1 >> m1 >> h2 >> m2 >> k;
        ll diff;
        if(h2>=h1) diff=h2-h1;
        else diff=24+h2-h1;

        diff*=60;

        diff+=m2-m1;
    

        cout << max(0ll,diff-k) << endl;
    }
}