#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr lint mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define rep2(i, l, r) for(int i = int(l); i < int(r); i++)
#define repr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define repr2(i, l, r) for(int i = int(r) - 1; i >= int(l); i--)
#define SZ(x) int(x.size())
constexpr int inf9 = 1e9; constexpr lint inf18 = 1e18;
inline void YES(bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
inline void Yes(bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
inline void assertNO(bool condition){ if(!condition){ cout << "NO" << endl; exit(0); } }
inline void assertNo(bool condition){ if(!condition){ cout << "No" << endl; exit(0); } }
inline void assertm1(bool condition){ if(!condition){ cout << -1 << endl; exit(0); } }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class T> string to_string(complex<T> x){ return to_string(make_pair(x.real(), x.imag())); }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) cout << (i == start ? "" : " ") << (*i); if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(b) return gcd(b, a % b); else return a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint P(int n, int r){ if(r < 0 || n < r) return 0; return (fact[n] * inv[n - r] % mod); } lint C(int p, int q){ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }
template<class itr, class itr2> bool next_sequence2(itr first, itr last, itr2 first2, itr2 last2){ itr now = last; itr2 now2 = last2; while(now != first){ now--, now2--; (*now)++; if((*now) == (*now2)){ (*now) = 0; }else{ return true; } } return false; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int at(lint i, int j){ return (i >> j) & 1; }
random_device rnd;
bool is_in_board(lint y, lint x, lint H, lint W){ return (0 <= y && y < H && 0 <= x && x < W); }

int main(){
    int H, W, M;
    cin >> H >> W >> M;
    int h[M], w[M];
    vector<int> row(H, 0), column(W, 0);
    rep(i, M){
        cin >> h[i] >> w[i];
        h[i]--, w[i]--;
        row[h[i]]++;
        column[w[i]]++;
    }
    int row_max = 0, column_max = 0;
    vector<int> row_max_pos, column_max_pos;
    rep(i, H){
        if(row_max < row[i]){
            row_max = row[i];
            row_max_pos = vector<int>(1, i);
        }else if(row_max == row[i]){
            row_max_pos.push_back(i);
        }
    }
    rep(i, W){
        if(column_max < column[i]){
            column_max = column[i];
            column_max_pos = vector<int>(1, i);
        }else if(column_max == column[i]){
            column_max_pos.push_back(i);
        }
    }
    vector<bool> is_row_max(H, false), is_column_max(W, false);
    for(int i: row_max_pos){
        is_row_max[i] = true;
    }
    for(int i: column_max_pos){
        is_column_max[i] = true;
    }
    int row_max_and_column_max = 0;
    rep(i, M){
        row_max_and_column_max += (is_row_max[h[i]] && is_column_max[w[i]]);
    }
    if(lint(row_max_pos.size()) * lint(column_max_pos.size()) == row_max_and_column_max){
        cout << row_max + column_max - 1 << endl;
    }else{
        cout << row_max + column_max << endl;
    }
}
