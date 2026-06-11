//
// Created by Koki Igarashi on 7/28/20.
//
 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef int Int;
typedef pair<Int, Int> pii;
typedef pair<Int, double> pid;
typedef pair<double, double> pdd;
typedef pair<Int, pii> pip;
typedef pair<pii, Int> ppi;
typedef pair<double, Int> pdp;
typedef vector<Int> veci;
typedef vector<double> vecd;
typedef vector<int> veci;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<pii> vecpii;
typedef vector<ppi> vecppi;
typedef vector<veci> mati;
typedef vector<vecll> matll;
typedef vector<vecd> matd;
#define PB(x) push_back(x)
#define EB(x) emplace_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (x).size()
#define len(x) (x).length()
#define CLR(x) memset(x,0,sizeof x)
#define pdebug() printf("%d\n",__LINE__)
#define REP(i, a, b) for(int i = (a);i <= (b);i++)
#define FORO(i, n) REP(i,0,(int)n-1)
#define FORI(i, n) REP(i,1,(int)n)
#define FORIT(i, t) for(auto i = t.begin();i != t.end();i++)
#define eps 1e-6
#define sqr(x) ((x)*(x))
#define dist(_a, _b) sqrt(sqr(_a.A-_b.A)+sqr(_a.B-_b.B))
#define norm(_a) sqrt(sqr(_a.A)+sqr(_a.B))
#define DEBUG true
#if DEBUG
#define DUMP(a) do { std::cout << #a " = " << (a) << ", "; } while(false)
#define DUMPLN(a) do { std::cout << #a " = " << (a) << std::endl; } while(false)
#else
#define DUMP(a)
#define DUMPLN(a)
#endif
template<typename T, typename U>
inline void getMin(T &a, U b) { if (a > b) a = b; }
template<typename T, typename U>
inline void getMax(T &a, U b) { if (a < b) a = b; }
template<typename T>
vector<T> getVector(const int n) { return vector<T>(n); }
template<typename T>
vector<T> getVector(const int n, const T a) { return vector<T>(n, a); }
template<typename T>
vector<T> getEmptyVector() { return vector<T>(); }
template<typename T>
void appendAll(vector<T> &a, vector<T> b) { a.insert(a.end(), b.begin(), b.end()); }
// #define X first
// #define Y second
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const ll MOD = 1000000007;
const int MAXN = 1 << 17;
const int inf = 1 << 20;
const int NIL = -inf;
int popcount(int x) { return __builtin_popcount(x); }
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string s, t;
    cin >> s >> t;
 
    veci al_pos[26];
    FORO(i, len(s)) {
        al_pos[s[i] - 'a'].EB(i);
    }
 
    veci index(26);
 
    ll ans = -1;
    int mk = 0;
    ll num_rep = 0;
    FORO(i, len(t)) {
        // DUMPLN(t[i]);
        int c_index = t[i] - 'a';
        if(SZ(al_pos[c_index]) == 0) {
            ans = -1;
            break;
        }
        while(al_pos[c_index][index[c_index]] < mk) {
            index[c_index]++;
            if(index[c_index] >= SZ(al_pos[c_index])) {
                break;
            }
        }
        if(index[c_index] >= SZ(al_pos[c_index])) {
            mk = 0;
            index.assign(26, 0);
            num_rep++;
        }
        getMax(mk, al_pos[c_index][index[c_index]]);
        // DUMP(c_index); DUMPLN(index[c_index]);
        // DUMP(num_rep); DUMPLN(mk);
        ll sr = (ll)len(s) * num_rep;
        getMax(ans, sr + al_pos[c_index][index[c_index]] + 1);
        index[c_index]++;
    }
 
    cout << ans << endl;
 
    return 0;
}