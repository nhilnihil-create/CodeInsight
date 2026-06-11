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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    vector<ll> sum(n+1);
    for(int i = 0; i < n; i++) sum[i+1] = sum[i] + a[i];
    vector<ll> b(n+1);
    for(int i = 0; i <= n; i++) {
        b[i] = (sum[i]-i+100000*k) % k;
    }
    map<ll, int> mp;
    queue<int> q;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += mp[b[i]];
        mp[b[i]]++;
        q.push(b[i]);
        while(q.size()>=k) {
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
}