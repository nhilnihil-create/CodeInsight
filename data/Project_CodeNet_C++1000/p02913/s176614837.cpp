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

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct RollingHash{
    const long long MASK30 = (1LL << 30) - 1;
    const long long MASK31 = (1LL << 31) - 1;
    const long long MOD = (1LL << 61) - 1;
    const long long MASK61 = MOD;

    int N;
    vector<long long> hs, b;
    long long base;

    RollingHash(string &s, long long base_=-1){
        if(base_ == -1){
            random_device rnd; // 非決定的な乱数生成器
            mt19937 mt(rnd());
            base = mt()+1;
        }
        else{
            base = base_;
        }

        N = s.size();
        hs.resize(N+1); b.resize(N+1); b[0] = 1; hs[0] = 0;
        for(int i=0; i<N; i++){
            b[i+1] = Mul(b[i], base);
            hs[i+1] = Mul(hs[i], base) + s[i];
            if(hs[i+1] >= MOD) hs[i+1] -= MOD;
        }
    }

    long long get(int l, int r){
        long long ret = hs[r] + MOD - Mul(hs[l], b[r - l]);
        if(ret >= MOD) ret -= MOD;
        return ret;
    }

    //mod 2^61-1を計算する関数
    long long CalcMod(long long x){
        long long xu = x >> 61;
        long long xd = x & MASK61;
        long long res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }

    //a*b mod 2^61-1を返す関数(最後にModを取る)
    long long Mul(long long a, long long b){
        long long au = a >> 31;
        long long ad = a & MASK31;
        long long bu = b >> 31;
        long long bd = b & MASK31;
        long long mid = ad * bu + au * bd;
        long long midu = mid >> 30;
        long long midd = mid & MASK30;
        return CalcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
};

void Main(){
    int N; cin >> N;
    string S; cin >> S;
    RollingHash rh(S);

    int l = 0, r = (N+1)/2+1;
    while(r-l>1){
        int k = (l+r)/2;
        map<ll,VI> m;
        REP(i,N-k+1){
            ll hash = rh.get(i,i+k);
            m[hash].push_back(i);
        }
        bool flag = false;
        for(auto& p : m){
            VI v = p.second;
            int K = v.size();
            REP(i,K-1){
                if(v.back() - v[i] >= k) flag = true;
            }
        }

        if(flag) l = k;
        else r = k;
    }

    cout << l << en;
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}