#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
//#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fm, ...) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout << "DEBUG PRINT ";std::printf(fm, __VA_ARGS__);}while(0)
#define DEBUG_VAL(a, b) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout <<"DEBUG VAL " << a << ":" << b << endl;}while(0)
#else
#define DEBUG_PRINT(...)do{}while(0);
#define DEBUG_VAL(a, b)do{}while(0);
#endif

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

ll MAX = 1e9+ 7;

ll ppow(ll x, ll y){
    ll ans = 1;
    for(ll i = 0;i < y; i++){
        ans *= x;
        ans %= MAX;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    ll all = ppow(10, n);
    all %= MAX;
    DEBUG_VAL("all", all);
    ll nin = ppow(9, n);
    nin %= MAX;
    DEBUG_VAL("nin", nin);
    ll kab = ppow(8, n);
    kab %= MAX;
    DEBUG_VAL("kab", kab);
    ll ans = all - 2*nin + kab;
    ans %= MAX;
    if(ans < 0) ans += MAX;
    cout << ans << endl; 
}
