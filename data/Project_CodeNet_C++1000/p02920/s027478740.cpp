#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const long long MOD = 1000000007LL;
const long long INF = 1e18;

int GCD(int a, int b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}
long long slow_mult(long long base, long long exp, long long mod = MOD) {
    long long tot = 0;
    for(;exp > 0;exp >>= 1){
       if((exp & 1) == 1) tot = (tot + base) % mod;
       base = base * 2 % mod;
    }
    return tot;
}

struct chash {
    static uint64_t splitmix64(uint64_t x) {x += 0x8e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf54876d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}
    size_t operator()(pair<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);}
};

vector<pair<int, int>> arr;

long long calc(long long q){
    return q * (q + 1) / 2;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    multiset<int> yeet, cur;
    vector<int> arr;

    for(int a, i = 0; i < (1 << n); ++i){
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    for(int i = 1; i < (1 << n); ++i)
        yeet.insert(-arr[i]);
    cur.insert(-arr[0]);

    for(int i = 0; i < n; ++i){
        vector<int> to_add = {};
        for(auto j : cur){
            auto it = yeet.upper_bound(j);
            if(it == yeet.end()){
                cout << "No";
                return 0;
            }
            to_add.push_back((*it));
            yeet.erase(it);
        }
        for(auto j : to_add)
            cur.insert(j);
    }

    cout << "Yes";

    return 0;

}
