#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void Main(){
    int N; cin >> N;
    VI A(N), B(N); REP(i,N) cin >> A[i]; REP(i,N) cin >> B[i];

    priority_queue<P> q;
    REP(i,N) q.emplace(B[i],i);

    ll ans = 0;
    while(q.size()){
        int i = q.top().second; q.pop();
        if(B[i] == A[i]) continue;
        int u = i>0 ? i-1 : N-1, v = i, w = (i+1)%N;
        int mx = max(B[u],B[w]);
        if(mx >= B[v]){
            cout << -1 << en;
            return;
        }
        int div = (B[v]-mx + B[u]+B[w]-1) / (B[u]+B[w]);
        if(B[u]==A[u] && B[w]==A[w]){
            if((B[v]-A[v])%(B[u]+B[w]) != 0){
                cout << -1 << en;
                return;
            }
            div = (B[v]-A[v]) / (B[u]+B[w]);
            ans += div;
            continue;
        }
        ans += div;
        B[v] -= div * (B[u]+B[w]);

        if(B[v] < A[v]){
            cout << -1 << en;
            return;
        }
        if(B[v] > A[v]) q.emplace(B[v],v);
    }
    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}