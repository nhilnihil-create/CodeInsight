#include <bits/stdc++.h>
using namespace std;

#define int long long
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

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

#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

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


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

#endif

#define mod 1000000007
//typedef pair<int, int> P;
#define INF (1LL<<60)


int N, M, V, P;
vector<int> A;

bool isOK(int idx){
    if(idx<P) return true;
    
    vector<int> B = A;
    
    B[idx] += M;
    
    if(B[idx]<B[P-1]) return false;
    
    swap(B[idx], B[P-1]);
    int rem = (V-P)*M;
    
    for(int i=P; i<N; i++){
        int t = min(M, B[P-1] - B[i]);
        rem -= t;
    }
    if(rem<=0) return true;
    else return false;
}


void solve(){
    cin >> N >> M >> V >> P;
    A.resize(N);
    rep(i,N) cin >> A[i];
    sort(ALL(A), greater<>());
    
    dump(A);
    
    int ng = N;
    int ok = 0;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        
        dump(mid, isOK(mid));

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    
    
    
    cout << ok+1 << endl;
}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
