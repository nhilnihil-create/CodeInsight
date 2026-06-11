#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    //入力＋ソート
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());

    //目標の成績kを達成可能かどうかを判定する関数
    auto ok = [&](ll x) {
        ll cost = 0;
        for(int i = 0; i < n; i++) {
            cost += max(0LL, a[i] - x/f[i]);
        }
        return cost <= k;
    };

    //二分探索
    ll l = -1, r = 1e18;
    while(r-l>1) {
        ll mid = (r+l)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
