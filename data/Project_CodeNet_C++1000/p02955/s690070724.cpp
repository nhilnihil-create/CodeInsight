#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
#define ALL(v) (v).begin(), (v).end()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
 
#if 1
//-------------
// DUMPマクロ
// https://www.creativ.xyz/dump-cpp-652/
 
// vector
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&& ... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
#endif


vector<int> divisor(int n){
    vector<int> ret;
    for (int i = 1; i*i <= n; i++){
        if (n%i == 0){
            ret.push_back(i);
            if (i*i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int sum=0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    
    vector<int> div = divisor(sum);
    sort(ALL(div), greater<>());
    for(int d : div){
        vector<int> rem(N);
        rep(i,N) rem[i] = A[i] % d;
        sort(ALL(rem));
        int s1 = 0, s2=0;;
        rep(i,N) if(rem[i]!=0) s2 += d - rem[i];
        if(s2<=K){ cout << d << endl; return;}
        rep(i,N){
            if(rem[i]==0) continue;
            s2 -= d - rem[i];
            s1 += rem[i];
            if(s1<=K && s2<=K){ cout << d << endl; return;}
        }
    }
    
}
signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
