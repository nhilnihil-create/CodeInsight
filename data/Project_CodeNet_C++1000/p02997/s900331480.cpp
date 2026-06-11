#include <bits/stdc++.h>
using namespace std;
 
#define INIT() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define ForLL(i, s, t) for (LL i = LL(s); i <= LL(t); ++i)
#define rForLL(i, t, s) for (LL i = LL(t); i >= LL(s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define rforeach(i,c) for (__typeof(c.rbegin()) i = c.rbegin(); i != c.rend(); ++i)
 
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
 
#define LOWBIT(x) ((x)&(-x))
 
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define REMOVE(x, c) x.erase(remove(x.begin(), x.end(), c), x.end()); // 删去 x 中所有 c 
#define TOLOWER(x) transform(x.begin(), x.end(), x.begin(),::tolower);
#define TOUPPER(x) transform(x.begin(), x.end(), x.begin(),::toupper);
 
#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,inf,sizeof(a))
#define msM(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define PB push_back
#define ft first
#define sd second
 
template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}
 
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}
 
template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
}

inline int gc(){
    static const int BUF = 1e7;
    static char buf[BUF], *bg = buf + BUF, *ed = bg;
    
    if(bg == ed) fread(bg = buf, 1, BUF, stdin);
    return *bg++;
} 

inline int ri(){
    int x = 0, f = 1, c = gc();
    for(; c<48||c>57; f = c=='-'?-1:f, c=gc());
    for(; c>47&&c<58; x = x*10 + c - 48, c=gc());
    return x*f;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

//min <= aim <= max
template<typename T>
inline bool BETWEEN(const T aim, const T min, const T max) {
    return min <= aim && aim <= max;
}
 
typedef long long LL;
typedef unsigned long long uLL;
typedef pair< double, double > PDD;
typedef pair< int, int > PII;
typedef pair< int, PII > PIPII;
typedef pair< string, int > PSI;
typedef pair< int, PSI > PIPSI;
typedef set< int > SI;
typedef set< PII > SPII;
typedef vector< int > VI;
typedef vector< double > VD;
typedef vector< VI > VVI;
typedef vector< SI > VSI;
typedef vector< PII > VPII;
typedef map< int, int > MII;
typedef map< int, string > MIS;
typedef map< int, PII > MIPII;
typedef map< PII, int > MPIII;
typedef map< string, int > MSI;
typedef map< string, string > MSS;
typedef map< PII, string > MPIIS;
typedef map< PII, PII > MPIIPII;
typedef multimap< int, int > MMII;
typedef multimap< string, int > MMSI;
//typedef unordered_map< int, int > uMII;
typedef pair< LL, LL > PLL;
typedef vector< LL > VL;
typedef vector< VL > VVL;
typedef priority_queue< int > PQIMax;
typedef priority_queue< int, VI, greater< int > > PQIMin;
const double EPS = 1e-8;
const LL inf = 0x7fffffff;
const LL infLL = 0x7fffffffffffffffLL;
const LL mod = 1e9 + 7;
const int maxN = 2e5 + 7;
const LL ONE = 1;
const LL evenBits = 0xaaaaaaaaaaaaaaaa;
const LL oddBits = 0x5555555555555555;

int N, K, M;

int main(){
    cin >> N >> K;
    M = N * (N - 1) / 2 - K;
    if(M < N - 1) M = -1;
    
    cout << M << endl;
    if(M != -1) {
        int cnt = N - 1;
        while(M > 0) {
            For(i, N - cnt + 1, min(N, N - cnt + M)) cout << N - cnt << " " << i << endl;
            M -= cnt--;
        }
    }
    return 0;
}