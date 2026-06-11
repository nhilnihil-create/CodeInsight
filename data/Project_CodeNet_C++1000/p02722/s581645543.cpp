#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,m,ans = 0;
    cin >> n;
    m = n-1;
    vector<ll> a,b;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            a.push_back(i);
            if(n/i != i)a.push_back(n/i);
        }
    }
    a.push_back(n);

    for(ll i=2;i*i<=m;i++){
        if(m%i==0){
            b.push_back(i);
            if(m/i != i)b.push_back(m/i);
        }
    }
    if(m!=1)b.push_back(m);

    for(auto k:a){
        ll now = n;
        while(now % k == 0 )now/=k;
        now %= k;
        if(now == 1)ans++;
    }
    cout << ans + b.size() << endl;
}