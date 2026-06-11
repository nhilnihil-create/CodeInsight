#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
template <typename T> 
using lim = numeric_limits<T>;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int N = 2e5;
ll n, k;
int A[N+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }

    int a, b;
    a = A[1];
    b = A[A[1]];
    while(a != b){
        a = A[a];
        b = A[A[b]];
    }

    int cnt = 0;
    a = 1;
    while(a != b){
        a = A[a];
        b = A[b];
        cnt++;
    }

    if (k <= cnt){
        a = 1;
        while(k--){
            a = A[a];
        }
        cout << a << "\n";
        return 0;
    }

    k -= cnt;
    int cycle = 1;
    b = A[a];
    while(a != b){
        b = A[b];
        cycle++;
    }

    k %= cycle;

    while(k--){
        a = A[a];
    }
    cout << a << "\n";
}