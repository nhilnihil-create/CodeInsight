#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<ll> VLL;
typedef vector<PLL> VP;
const static int INF = 1000000000;
const static int MOD = 1000000007;
const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "
//charを整数に
int ctoi(char c) { if (c >= '0' && c <= '9') { return c - '0'; } return 0; }
// 累積和 for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i]; 
void cum_sum(int N,vector<double> a, vector<double> &s){ for(int i=0; i<N; i++){ s[i+1]=s[i]+a[i];}}
//ユークリッドの控除法
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
//最小公倍数
ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}
//素数判定
bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}
int getdigit(ll num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
//空白文字も入力 getline(cin, S);
//桁数指定 setprecision

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    vector<vector<int>> G;
    ll N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;
    G.resize(N);
    rep(i,N-1){
        G[i].PB(i+1);
        G[i+1].PB(i);
    }
    G[X].PB(Y);
    G[Y].PB(X);
    map<ll, ll> ans;
    for(ll i=0; i<N; i++){
        VLL dist(N, -1);
        queue<ll> que;
        dist[i]=0;
        que.push(i);
        while(!que.empty()){
            ll v=que.front();
            que.pop();
            for(ll nv : G[v]){
                if(dist[nv]!=-1) continue;
                dist[nv]=dist[v]+1;
                if(i<nv){
                    ans[dist[nv]]++;
                }
                que.push(nv);
            }
        }
    }
    for(int i=1; i<N; i++){
        cout << ans[i] << endl;
    }
}