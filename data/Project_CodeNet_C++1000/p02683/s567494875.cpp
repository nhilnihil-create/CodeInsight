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

const int N = 12;
int A[N][N];
int C[N];
int total[N];
int n, m, x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;

    for (int i = 0; i < n; i++){
        cin >> C[i];
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
            total[j] += A[i][j];
        }
    }


    int hi = 1 << n;
    int ans = 1e9;
    for (int i = 0; i < hi; i++){
        memset(total, 0, sizeof total);
        int cost = 0;
        for (int j = 0; j < n; j++){
            if ((1 << j)&i){
                cost += C[j];
                for (int k = 0; k < m; k++){
                    total[k] += A[j][k];
                }
            }
        }
        bool valid = 1;
        for (int k = 0; k < m; k++){
            valid &= total[k] >= x;
        }

        if(valid){
            ans = min(ans, cost);
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
}