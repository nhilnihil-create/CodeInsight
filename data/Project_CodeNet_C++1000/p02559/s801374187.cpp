#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef pair<int,int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define EXIST(m,v) (m).find((v)) != (m).end()
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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct BIT{
    private:
        using Func = function<T(T, T)>;

        int n;
        vector<T> node;

        T init_v;
        Func func;

    public:

        BIT(int N, Func _func, T _init_v) {
            n = N + 1;
            init_v = _init_v;
            func = _func;

            node.resize(n, init_v);
            for(int i=1; i<n; i++) if((i+(i&-i)) < n) node[i+(i&-i)] = func(node[i+(i&-i)], node[i]);
        }

        BIT() {}

        void add(int pos, T v) {
            // 0-indexed
            pos++;
            while(pos < n){
                node[pos] = func(node[pos], v);
                pos += pos & -pos;
            }
        }

        T sum(int pos){
            // 0-indexed
            // [0,pos]の総和
            pos++;
            T res = init_v;
            while(pos > 0){
                res = func(res, node[pos]);
                pos = pos & (pos-1);
            }
            return res;
        }

        T sum(int l, int r){
            // 0-indexed
            // [l,r)の総和
            return sum(r-1) - sum(l-1);
        }
};
ll f(ll a, ll b){return a+b;}

void Main(){
    int N,Q; cin >> N >> Q;
    BIT<ll> bit(N,f,0);
    REP(i,N){
        ll a; cin >> a;
        bit.add(i,a);
    }

    REP(_,Q){
        int t; cin >> t;
        if(t == 0){
            ll p,x; cin >> p >> x;
            bit.add(p,x);
        }
        else{
            int l,r; cin >> l >> r;
            cout << bit.sum(l,r) << en;
        }
    }
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}