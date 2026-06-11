#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD7 1000000007
#define LL_INF 1LL << 60
#define LL_MINF -1LL << 60
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long double PI = (acos(-1));



int main(){
    int N;
    cin >> N;
    vector<pair<ll,ll>> BA(N);
    for(int i = 0; i < N; i++) cin >> BA[i].se >> BA[i].fi;
    ll time = 0;
    bool ok = true;
    sort(all(BA));
    for(int i = 0; i < N; i++){
        time+=BA[i].se;
        if(time > BA[i].fi){
            ok = false;
            break;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
}