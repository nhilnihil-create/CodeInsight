#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> a(N),b(N);
    priority_queue<pair<ll,ll>> pq;
    REP(i,N) cin >> a[i];
    REP(i,N){
        cin >> b[i];
        pq.push({b[i],i});
    }
    ll ans = 0;
    while(!pq.empty()){
        ll now = pq.top().first;
        ll idx = pq.top().second;
        pq.pop();

        if(now == a[idx]) continue;
        else if(a[idx] > now){
            cout << -1 << endl;
            return 0;
        }
        else{
            ll sa = b[idx] - a[idx];
            ll wa = b[(idx-1+N)%N] + b[(idx+1)%N];
            if(sa / wa <= 0){
                cout << -1 << endl;
                return 0;
            }
            ans += sa / wa;
            now -= (sa / wa) * wa;
            b[idx] = now;
            pq.push({b[idx],idx});
        }
    }
    REP(i,N) if(a[i] != b[i]){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
