#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//const int mod = 998244353;
const int N = 2000005;
const int K = 1000000;
vector < int > ans[N];
vector < int > pol;
int mod;
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
vector < int > mp(vector < int > p, int x, int y){
    vector < int > res;
    int c = 0;
    for (int i = 0; i < p.size(); i++){
        p[i] += c;
        res.pb((p[i] * x % mod + mod) % mod);
        c = (y * (p[i] - c) % mod + mod) % mod;
    }
    res.pb(c);
    return res;
}
vector < int > dv(vector < int > p, int x, int y){
    vector < int > res;
    int c = 0;
    for (int i = 0; i < p.size() - 1; i++){
        p[i] += c;
        res.pb((p[i] % mod + mod) % mod);
        c = (-y * p[i] % mod + mod) % mod;
    }
    return res;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    int tx = 0;
    vector < int > v1, v2, v3;
    cin >> n;
    tx = 0;
    for (int i = 1; i <= n; i++){
        tx ^= i;
    }
    int m = n;
    while(m % 2 == 0) m /= 2;
    if (m == 1){
        cout << "No";
        return 0;
    }
    if (tx == 0){
        cout << "Yes" << endl;
        for (int i = 1; i < n + n; i++){
            cout << i << " " << i + 1 << endl;
        }
        return 0;
    }
    if (tx == 1){
        v1.pb(1);
        v2.pb(2);
        v2.pb(3);
        for (int i = 4; i <= n; i++){
            v3.pb(i);
        }
    } else{
        int z = 1;
        while(z + z <= tx) z += z;
        v1.pb(z);
        if ((tx ^ z) != 0) v1.pb((tx ^ z));
        v2.pb(z + 1);
        if ((tx ^ (z + 1)) != 0) v2.pb((tx ^ (z + 1)));
        for (int i = 1; i <= n; i++){
            int f = 1;
            for (auto j: v1) if (i == j) f = 0;
            for (auto j: v2) if (i == j) f = 0;
            if (f) v3.pb(i);
        }
    }
    cout << "Yes" << endl;
    set < pair < int, int > > ans;
    vector < int > t1, t2;
    for (auto j: v1) t1.pb(j);
    for (auto j: v2) t1.pb(j);
    for (auto j: v1) t1.pb(j + n);
    for (auto j: v2) t1.pb(j + n);
    for (auto j: v3) t2.pb(j);
    for (auto j: v2) t2.pb(j);
    for (auto j: v3) t2.pb(j + n);
    for (int i = 0; i < t1.size() - 1; i++){
        ans.insert({min(t1[i], t1[i + 1]), max(t1[i], t1[i + 1])});
    }
    for (int i = 0; i < t2.size() - 1; i++){
        ans.insert({min(t2[i], t2[i + 1]), max(t2[i], t2[i + 1])});
    }
    for (auto i: ans){
        cout << i.F << " " << i.S << endl;
    }
}
