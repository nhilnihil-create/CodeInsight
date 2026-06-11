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

#define en 


constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void Main(){
    int n;
    cin >> n;
    VI pv(n);
    REP(i, n) cin >> pv[i];
    VI qv(n);
    REP(i, n) cin >> qv[i];
    int a, b;
    VI v(n);
    REP(i, n) v[i] = i + 1;
    int count = 0;
    do {
        count++;
        int f = 0;
        REP(i, n) if (v[i] != pv[i]) f = 1;
        if (f == 0) a = count;
    } while (next_permutation(ALL(v)));
    REP(i, n) v[i] = i + 1;
    count = 0;
    do {
        count++;
        int f = 0;
        REP(i, n) if (v[i] != qv[i]) f = 1;
        if (f == 0) b = count;
    } while (next_permutation(ALL(v)));
    cout << abs(a-b) << endl;

}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}