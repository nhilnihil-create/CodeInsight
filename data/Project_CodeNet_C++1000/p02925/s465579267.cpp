#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int N;

int p2n(pair<int,int> p){
    int i = min(p.first, p.second), j = max(p.first, p.second);
    return N*(N-1)/2 - (N-i)*(N-i-1)/2-1 + j-i;
}

int main(void){
    cin >> N;
    int A[N][N-1];
    REP(i,N)REP(j,N-1){
        int a; cin >> a;
        a--;
        A[i][j] = a;
    }
    int n = N*(N-1)/2;
    vector<int> edge[n+1], deg(n+1,0);
    REP(i,N)REP(j,N-2){
        int from = p2n(pair<int,int>(i, A[i][j]));
        int to = p2n(pair<int,int>(i, A[i][j+1]));
        edge[from].push_back(to);
        deg[to]++;
    }

    REP(i,n){
        if(deg[i] == 0){
            edge[n].push_back(i);
            deg[i]++;
        }
    }

    if(edge[n].size() == 0){
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    queue<pair<int,int>> q;
    q.push(P(n,0));
    while(q.size()){
        auto p = q.front(); q.pop();
        int node = p.first, day = p.second;
        chmax(ans, day);
        for(int e : edge[node]){
            deg[e]--;
            if(deg[e] < 0){
                cout << -1 << endl;
                return 0;
            }
            else if(deg[e] == 0){
                q.push(P(e, day+1));
            }
        }
    }

    REP(i,n){
        if(deg[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}