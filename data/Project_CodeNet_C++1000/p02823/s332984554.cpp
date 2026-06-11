#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)

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

ll f(char x, ll r, ll s, ll p){
    if(x == 's') return r;
    else if(x == 'r') return p;
    else return s;
}

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    if(abs(b-a)%2 == 0) cout << (abs(b-a))/2 << endl;
    else {
        cout << min(min(a,b) - 1 + 1 + (abs(b-a)-1)/2, n - max(a,b) + 1 + (abs(b-a)-1)/2) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //ll t; cin >> t; while(t--)
        solve();
}
