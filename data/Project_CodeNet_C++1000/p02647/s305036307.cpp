#pragma region header
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;
/* ----------------よく使う数字や配列----------------- */
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr int inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */

/* --------------------テンプレート------------------ */
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
/* ----------------------end----------------------- */

/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ----------------------end----------------------- */
#pragma endregion
signed main() {
    int n,k;cin >> n >> k;
    vi a(n);
    // vi table(n);
    vi set(n,0);
    rep(i, n){
        cin >> a[i];
        /*table[max(i-a[i],0LL)]++;
        table[min(i+a[i],n-1)]--;
        if(i>0) table[i]+=table[i-1];*/
    }
    chmin(k,1000LL);
    rep(j, k) {
        if(j>0)a = set;
        fill(set.begin(),set.end(),0);
            rep(i, n) {
            set[max(i-a[i],0LL)]++;
            if(i+a[i]<n-1) set[i+a[i]+1]--;
            
            // cout << set[i] << ' ';
        }
        rep1(i, n-1) set[i]+=set[i-1];
        // for(int i = )
        // for(auto p:set) cout << p << ' ';cout << endl;
    }
    for(auto  p:set) cout << p << ' ';
    return 0;
}