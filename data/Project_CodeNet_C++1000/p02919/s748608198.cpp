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

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

#endif


#define mod 1000000007
typedef pair<int, int> P;
#define INF (1LL<<60)

void solve(){
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> idx(N);
    rep(i,N){
        cin >> P[i];
        P[i]--;
        idx[P[i]] = i;
    }
    dump(idx);
    
    int ans = 0;
    set<int> s;
    for(int k=N-1; k>=0; k--){
        int p = idx[k];
        if(k<N-1){

            auto ridx = s.lower_bound(p);
            int r=N, r2=N;
            // pが今までで一番大きい
            if(ridx==s.end()){
                r = N; r2 = N;
            }else{
                r = *ridx;
                ridx++;
                if(ridx==s.end()) r2 = N;
                else r2 = *ridx;
            }
            
            auto lidx = s.lower_bound(p);
            int l=-1, l2=-1;
            // pが今までで一番小さい
            if(lidx==s.begin()){
                l = -1;
                l2 = -1;
            }else{
                lidx--;
                l = *lidx;
                if(lidx==s.begin()){
                    l2 = -1;
                }else{
                    lidx--;
                    l2 = *lidx;
                }
            }

            
            int tmp = (l-l2)*(r-p) + (r2-r)*(p-l);
            ans += ((l-l2)*(r-p) + (r2-r)*(p-l)) * (k+1);

            dump(p, s, l2, l, r, r2, tmp);
        }
        s.insert(p);
    }
    cout << ans << endl;

}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
