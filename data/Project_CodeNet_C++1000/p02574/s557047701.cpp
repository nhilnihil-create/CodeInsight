#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define AfterDecimal(n) cout << fixed << setprecision(n);
#define ll long long int
#define ld long double
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bits(x) __builtin_popcount(x)

using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;

#ifdef LOCAL
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << "# "<< name << " = " << arg1 << '\n';
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1 && arg1, Args &&... args){
        const char* comma = strchr(names + 1 ,',');
        cout << "# ";
        cout.write(names, comma - names)<< " = " << arg1 << " | ";
        __f(comma + 1, args...);
}
#else
#define debug(...) 36
#endif


std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

ll power(ll x, ll y, ll p){
   ll res = 1;
   x = x % p;
   while (y > 0) {
      if (y & 1)
         res = (res * x) % p;
      y = y >> 1;
      x = (x * x) % p;
   }
   return res;
}

const ll INF = (ll)(8e18);
const ll MOD = (ll)(1e9 + 7);
const ll HMOD = (ll)4222234727;
const ll Hashprime = (ll)31;

const int maxn = 1000100;

// Primes in O(nlog(log(n)))
int spf[maxn], pr[maxn];

void sieve(){
    spf[1] = 1;
    for (int i = 2; i < maxn; i++) spf[i] = i;
    for (int i = 4; i < maxn; i += 2) spf[i] = 2;
    for (int i = 3; i * i < maxn; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < maxn; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}


int32_t main(){
    IOS;
    #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif
    int t = 1; // cin >> t;
    while(t--){
      int n; cin >> n;
      std::vector<int> a(n + 1);
      int tval = 0;
      for(int i = 1; i <= n; i++) cin >> a[i];
      sieve();
      for(int i = 1; i <= n; i++){
        tval = __gcd(tval, a[i]);
        int val = a[i];
        map <int, int> mp;
        while(val != 1) {
            if(mp.find(spf[val]) == mp.end()) pr[spf[val]] += 1;
            mp[spf[val]] += 1;
            val = val / spf[val];
        }
      }
      bool flag = true;
      for(int i = 1; i < maxn; i++){
         if(pr[i] > 1) flag = false;
      }
      if(flag) cout << "pairwise coprime" << '\n';
      else{
        if(tval == 1) cout << "setwise coprime" << '\n';
        else cout << "not coprime" << '\n';
      }
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
//g++ -DLOCAL -std=c++17 -Wshadow -Wall -o "c" "comp.cpp" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
