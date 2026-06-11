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




void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    
    vector<int> sum(N+1,0);
    map<int,vector<int>> m;
    m[0].push_back(0);
    rep(i,N){
        sum[i+1] = (sum[i] + A[i]-1) % K;
        m[sum[i+1]].push_back(i+1);
    }
    int ans = 0;
    for(auto i=m.begin(); i!=m.end(); i++){
        int a = i->first;
        vector<int>& v=i->second;
        
        for(int j=0; j<v.size(); j++){
            ans += lower_bound(v.begin()+j, v.end(), v[j]+K) - (v.begin()+j)-1;
        }
    }
    cout << ans << endl;
    
}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
