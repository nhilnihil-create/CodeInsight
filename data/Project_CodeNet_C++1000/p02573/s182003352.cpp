#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
const long long MOD = 1e9 + 7;
///////////////////////////////////////////////
// for template
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size,-1) { }

    int root(int x){
        if (data[x] < 0) return x;
        else return data[x] = root(data[x]);
    }

    int size(int x){
        return -data[root(x)];
    }

    bool isConnect(int x,int y){
        return root(x) == root(y);
    }

    bool connect(int x , int y){
        x = root(x);
	    y = root(y);
	
        if(x==y) return false;
        
        if(data[x] > data[y]){
            x ^= y;
            y ^= x;
            x ^= y;
        }
        
        data[x] = data[x] + data[y]; // membersize++
        data[y] = x;
        return true;
    }
};

UnionFind U(300002);

int main() {
    int N,M; cin >> N >> M;
    REP(i,M){
        int a,b; cin >> a >> b;
        U.connect(a - 1,b - 1);
    }

    int ans = 0;
    REP(i,N){
        if (U.root(i) != i) continue;
        chmax(ans, U.size(i));
    }
    cout << ans << endl;
}