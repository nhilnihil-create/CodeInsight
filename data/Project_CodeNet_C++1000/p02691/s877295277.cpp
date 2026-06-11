#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;
ll D2 = 998244353LL;
using namespace std;

ll n, m, k;

int main(){
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> dfs;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        dfs[i - a[i]] += 1;
    }
    ll ctr = 0;

    for(int i=0; i<n; ++i){
        ctr += dfs[a[i] + i];
    }
    cout << ctr << endl;
    return 0;
}