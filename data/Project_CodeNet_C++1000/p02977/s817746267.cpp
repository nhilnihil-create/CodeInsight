#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr ll MOD = (ll)1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr ll HIGHINF = (ll)1e18;
constexpr ll LOWINF = (ll)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template<typename T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template<typename... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

int main() {
    int N; cin >> N;
    V<int> pow2(N+1,0);
    for(int i = 1; i <= N+1; i *= 2) pow2[i] = 1;    
    corner(pow2[N],"No");

    V<int> flg(2*N+1,0);
    V<int> u,v;
    u.push_back(N+1); v.push_back(N+2);
    u.push_back(N+2); v.push_back(N+3);
    u.push_back(N+3); v.push_back(1);
    u.push_back(1); v.push_back(2);
    u.push_back(2); v.push_back(3);
    flg[N+3] = flg[2] = 1;
    

    for(int i = 4; i+1 <= N; i += 2){
        u.push_back(i); v.push_back(i+1);
        u.push_back(i+1); v.push_back(1);
        u.push_back(1); v.push_back(i+N);
        u.push_back(i+N); v.push_back(i+1+N);
        flg[i+1] = flg[i+N] = 1;
    }
    if(!(N%2)){
        int tmp = 1;
        for(int i = 2; i < N && tmp; ++i){
            int k = N^i^1;
            if(k<N){
                tmp = 0;
                u.push_back(N); v.push_back(i + (flg[i]?0:N));
                u.push_back(2*N); v.push_back(k + (flg[k]?0:N));
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < 2*N-1; ++i) cout << u[i] << " " << v[i] << endl;

    return 0;
}
