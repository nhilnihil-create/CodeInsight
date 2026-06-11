#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

// 線分ab の偏角 [-π, π] を返す
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax = a.first, ay = a.second, bx = b.first, by = b.second;
    return atan2(by - ay, bx - ax);
}

// 偏角ソート
void argumentSort(vector<pair<long double, long double>> &v){
    pair<long double, long double> o(0, 0);
    sort(v.begin(), v.end(), [&](auto a, auto b){return argument(o, a) < argument(o, b);});
}

void solve(){
    int n;
    cin >> n;
    vector<pair<long double, long double>> xy;
    REP(i,n){
        long double a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) continue;
        xy.emplace_back(a, b);
    }
    argumentSort(xy);
    long double ans = 0;
    int m = xy.size();
    REP(i,m){
        long double x = 0, y = 0;
        REP(j,m){
            x += xy[(i+j)%m].first;
            y += xy[(i+j)%m].second;
            chmax(ans, hypot(x, y));
        }
    }
    printf("%.12Lf\n", ans);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}