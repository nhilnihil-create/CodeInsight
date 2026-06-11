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
    cin >> n >> m;
    vector<ll> h(n);
    for (int i=0; i<n; ++i) cin >> h[i];
    map<ll, set<ll> > rt;
    for(int i=0; i<m; ++i){
        ll a,b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        rt[a].insert(b);
        rt[b].insert(a);
    }
    ll ctr = n;
    for(int i=0; i<n; ++i){
        for (auto it = rt[i].begin(); it != rt[i].end(); ++it){
            if (h[i] <= h[*it]){
                ctr--;
                break;
            }
        }
    }
    cout << ctr << endl;

    return 0;
}