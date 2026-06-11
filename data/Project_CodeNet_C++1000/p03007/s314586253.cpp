#include <bits/stdc++.h>
using namespace std;

#define int long long
//typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
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


signed main() {

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    
    sort(A.begin(), A.end(), greater<int>());
    
    int plus = 0;
    rep(i,N) if(A[i]>0) plus++;
    
    if(plus==0) plus=1;
    if(plus==N) plus=N-1;

    int minus = N-plus;
    
    int ans=0;
    rep(i,plus) ans+= A[i];
    rep(i,minus) ans-= A[N-i-1];
    
    cout << ans << endl;
    
    int a = A[0];
    rep(i,minus-1){
        cout << a << " " << A[plus+i] << endl;
        a -= A[plus+i];
    }
    
    int b = A[N-1];
    rep(i,plus-1){
        cout << b << " " << A[i+1] << endl;
        b -= A[i+1];
    }
    
    cout << a << " " << b << endl;
    
    
}

