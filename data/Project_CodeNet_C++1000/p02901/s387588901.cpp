#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 29);
const ll LINF = 1e18;
const double PI = acos(-1);

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template <typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
    for(auto &e:t) fill_v(e,v);
}
template<class T> bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1;}
    return 0;
}
template<class T> bool chmin(T & a, const T & b) { if (a > b) { a = b; return 1;}
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    auto dp = make_v<int>(M,2,1<<N);
    fill_v(dp,INF);
    vi V(M);
    vi A(M);
    REP(i,M){
        int b;
        cin >> A[i] >> b;
        REP(j,b){
            int C;
            cin >> C;
            V[i]+= 1 << (C-1);
        }
    }
    
    dp[0][0][0] = 0;
    REP(i,M){
        if(i != 0){
            REP(j,SZ(dp[i][0]))dp[i][0][j] = min(dp[i-1][0][j],dp[i-1][1][j]);
        }
        REP(j,(1<<N)){
            REP(k,N){
                if((V[i] & (1 << k)) != 0){
                    if((j & (1 << k)) == 0){
                        chmin(dp[i][1][j + (1 << k)],min(dp[i][1][j],dp[i][0][j] + A[i]));
                    }
                }
            }
        }
    }
    int ans = min(dp[M-1][0][(1 << N)-1],dp[M-1][1][(1<<N)-1]);
    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}