//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){

    int N;
    cin >> N;
    int P[N];
    REP(i,N) cin >> P[i];
    int idx[N];
    REP(i,N) idx[P[i]-1] = i+1;

    set<int> s;
    ll ans = 0;
    for(int x=N; x>0; x--){
        ll c;
        int i = idx[x-1];
        s.insert(i);
        int l[2] = {0,0}, r[2] = {N+1,N+1};
        auto itr = s.find(i);
        REP(j,2){
            if(itr == s.begin()) break;
            itr--;
            l[j] = *itr;
        }
        itr = s.find(i);
        REP(j,2){
            itr++;
            if(itr == s.end()) break;
            r[j] = *itr;
        }
        c = (ll)(i-l[0])*(r[1]-r[0]) + (ll)(r[0]-i)*(l[0]-l[1]);
        ans += c*x;
    }

    cout << ans << endl;
    
    return 0;
}