#include <bits/stdc++.h>
using namespace std;


#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;

int n, m;
vector<int> s,t;

int main() {
    cin >> n >> m;
    int v;
    rp(i, 0, n){
        scanf("%d", &v);
        s.emplace_back(v);
    }
    rp(i, 0, m){
        scanf("%d", &v);
        t.emplace_back(v);
    }

    vector<vector<ll>> dp(2020, vector<ll>(2020));
    rp(i, 0, m+1){
        dp.at(0).at(i) = 1;
    }
    rp(i, 0, n+1){
        dp.at(i).at(0) = 1;
    }
    rp(i, 1, n+1){
        rp(j, 1, m+1){
            if(s.at(i-1) == t.at(j-1)) dp.at(i).at(j) = (dp.at(i).at(j-1) + dp.at(i-1).at(j))%mod;
            else dp.at(i).at(j) = (mod + dp.at(i).at(j-1) + dp.at(i-1).at(j) - dp.at(i-1).at(j-1))%mod;
        }
    }
    printf("%lld", dp.at(n).at(m));

}
