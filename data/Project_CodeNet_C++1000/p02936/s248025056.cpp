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
constexpr long long MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, q;
VVI ev;
VI pv;
VI ansv;
VI usedv;

void dfs(int v, int point) {
    if (usedv[v] == 1) {
        return;
    }
    usedv[v] = 1;
    point += pv[v];
    ansv[v] = point;
    REP(i, ev[v].size()) {
        dfs(ev[v][i], point);
    }
}
void Main(){
    cin >> n >> q;
    REP(i, n) {
        pv.push_back(0);
        ansv.push_back(0);
        usedv.push_back(0);
    }
    ev.resize(n);
    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        ev[a-1].push_back(b-1);
        ev[b-1].push_back(a-1);
    }
    REP(i, q) {
        int p, x;
        cin >> p >> x;
        pv[p-1] += x;
    }
    dfs(0, 0);
    REP(i, n) {
        cout << ansv[i] << endl;
    }
}   

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}

