//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

bool comp(pll a, pll b){
    return atan2(a.S, a.F) < atan2(b.S, b.F);
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;

    sort(iter(a), comp);
    a.resize(2 * n);
    for(int i = n; i < 2 * n; i++) a[i] = a[i - n];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        
        pll now = mp(0, 0);
        
        for(int j = 1; j <= n; j++){
            now.F += a[i + j].F;
            now.S += a[i + j].S;
            ans = max(ans, now.F * now.F + now.S * now.S);
        }

    }

    cout << fixed << setprecision(12) << sqrt(ans) << "\n";

    return 0;
}