#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;


//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


struct Edge {
    int to, from;
    ll cost;
    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
AdjList graph;

int dp[100010][2];
int mp[200010];
int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);
    int N;
    string s; cin >> N >> s;

    
    for(int i=0; i<s.size(); ++i){
        
        if(i==0) mp[i] = (s[i]=='W')?0:1;
        else mp[i] = (s[i]==s[i-1])?0:1;
        //cout << mp[i];
    }
    //cout << endl;


    ll ans = 1;
    ll X = 0;
    for(int i=0; i<s.size(); ++i){
        if(mp[i] == 0){
            if(X==0){
                cout << 0 << endl;
                return 0;
            }
            ans *= X;
            X--;
            mp[i+1]^= 1;
        }else{
            X++;
        }
        ans %= MOD;
    }

    if(X != 0){
        cout << 0 << endl;
    }else{
        for(int i=1; i<=N; ++i){
            ans = (ll)ans * i;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;

}