#include <bits/stdc++.h>
#include <complex>
#include <iomanip>

using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef unsigned long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

void kill()
{
  cout << -1 << endl;
  exit(0);
}

#if 1
int main()
{
    int N;
    ll ans = 0;
    cin >> N;
    vector<int> A(N), B(N);
    priority_queue<pair<int, int>> q;
    
    
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < N; i++){
        cin >> B[i];
        q.push(make_pair(B[i], i));
    }
    while (q.size() > 0){
        int i = q.top().second;
        q.pop();
        
        int b = B[i];
        int a = B[(N + i - 1)%N];
        int c = B[(i + 1)%N];
        
        if(b == A[i]) 
            continue;
        if (b < A[i]){
            kill();
        }
#if 1
        int times = (b - A[i])/(a+c);
        ans += times;
        b -= times * (a+c);
#endif
        if (times == 0){
            kill();
        }
        q.push(make_pair(b, i));
        B[i] = b;
//        int ii;
//        for (int i = 0; i < N; i++){
//            fprintf(stderr, "%d, ", B[i]);
//        }
//        fprintf(stderr, "\n");
#if 0
        for (int i = 0; i < N; i++){
            if (pquea.top() > pque.top()){
                cout<<-1<<endl;
                return 0;
            }
        
            if (1 ||  pquea.top() == pque.top()){
                int ii;
                for (ii = 0; ii < N; ii++){ 
                    if (A[ii] > B[ii]){
                        cout<<-1<<endl;
                        return 0;
                    }
                        
                    if (A[ii] != B[ii]){
                        break;
                    }
                }
                if (ii == N){
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
#endif
    }
    cout<<ans<<endl;
    return 0;
}


#else

#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
#define i64         int64_t
#define rep(i, n)   for(i64 i = 0; (i) < ((i64)(n)); ++(i))
#define bit(n)      (((i64)1)<<((i64)(n)))
#define sz(v)       ((i64)((v).size()))

std::string dbgDelim(int &i){ return (i++ == 0 ? "" : ", "); }
#define dbgEmbrace(exp) { int i = 0; os << "{"; { exp; } os << "}"; return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> v);
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q);
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp);
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp);
template <int INDEX, class TUPLE> void dbgDeploy(std::ostream &os, TUPLE _){}
template <int INDEX, class TUPLE, class H, class ...Ts> void dbgDeploy(std::ostream &os, TUPLE t){ os << (INDEX == 0 ? "" : ", ") << get<INDEX>(t); dbgDeploy<INDEX + 1, TUPLE, Ts...>(os, t); }
template <class T, class K> void dbgDeploy(std::ostream &os, std::pair<T, K> p, std::string delim){ os << "(" << p.first << delim << p.second << ")"; }
template <class ...Ts> std::ostream& operator<<(std::ostream &os, std::tuple<Ts...> t){ os << "("; dbgDeploy<0, std::tuple<Ts...>, Ts...>(os, t); os << ")"; return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::pair<T, K> p){ dbgDeploy(os, p, ", "); return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> v){ dbgEmbrace( for(T t: v){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> s){ dbgEmbrace( for(T t: s){ os << dbgDelim(i) << t; }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::queue<T> q){ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << q.front(); }); }
template <class T> std::ostream& operator<<(std::ostream &os, std::priority_queue<T> q){ dbgEmbrace( for(; q.size(); q.pop()){ os << dbgDelim(i) << (T) q.top();   }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> mp){ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::unordered_map<T, K> mp){ dbgEmbrace( for(auto p: mp){ os << dbgDelim(i); dbgDeploy(os, p, "->"); }); }
#define DBG_OUT std::cerr
#define DBG_OVERLOAD(_1, _2, _3, _4, _5, _6, macro_name, ...) macro_name
#define DBG_LINE() { char s[99]; sprintf(s, "line:%3d | ", __LINE__); DBG_OUT << s; }
#define DBG_OUTPUT(v) { DBG_OUT << (#v) << "=" << (v); }
#define DBG1(v, ...) { DBG_OUTPUT(v); }
#define DBG2(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG1(__VA_ARGS__); }
#define DBG3(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG2(__VA_ARGS__); }
#define DBG4(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG3(__VA_ARGS__); }
#define DBG5(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG4(__VA_ARGS__); }
#define DBG6(v, ...) { DBG_OUTPUT(v); DBG_OUT << ", "; DBG5(__VA_ARGS__); }

#define DEBUG0() { DBG_LINE(); DBG_OUT << std::endl; }
#define DEBUG(...)                                                      \
  {                                                                     \
    DBG_LINE();                                                         \
    DBG_OVERLOAD(__VA_ARGS__, DBG6, DBG5, DBG4, DBG3, DBG2, DBG1)(__VA_ARGS__); \
    DBG_OUT << std::endl;                                               \
  }


void kill()
{
  cout << -1 << endl;
  exit(0);
}

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  priority_queue<pair<i64, i64>> q;
  rep(i, n) q.push(make_pair(b[i], i));

  i64 ans = 0;
  while(0 < sz(q)){
    // DEBUG(q);
    i64 i = q.top().second;
    q.pop();
    if(b[i] == a[i]) continue;
    if(b[i] < a[i]) kill();

    i64 prev = (i - 1 + n) % n;
    i64 next = (i + 1 + n) % n;
    i64 total = b[prev] + b[next];
    i64 times = (b[i]- a[i]) / total;
    // DEBUG(b[i], total, times);
    if(times == 0) kill();
    ans += times;
    b[i] -= total * times;
    q.push(make_pair(b[i], i));
  }

  cout << ans << endl;
}
#endif
