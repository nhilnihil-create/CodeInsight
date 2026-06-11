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
constexpr long long MOD = 10000; // 998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int win(int i){
    if(i==0) return 2;
    else if(i==1) return 0;
    else return 1;
}

void Main(){
    int N,K; cin >> N >> K;
    int s[3]; REP(i,3) cin >> s[i];
    VVI T(K);
    REP(i,N){
        char c; cin >> c;
        if(c=='r') T[i%K].push_back(0);
        else if(c=='s') T[i%K].push_back(1);
        else T[i%K].push_back(2);
    }

    int ans = 0;
    REP(i,K){
        if(T[i].empty()) continue;
        int k = T[i].size();
        vector<P> v{P(T[i][0],1)};
        REP(j,k-1){
            if(v.back().first == T[i][j+1]) v.back().second++;
            else v.emplace_back(T[i][j+1],1);
        }
        for(auto& p : v){
            ans += s[win(p.first)] * ((p.second+1)/2);
        }
    }

    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}