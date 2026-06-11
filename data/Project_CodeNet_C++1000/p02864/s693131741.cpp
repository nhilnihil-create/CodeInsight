#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T &b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T &b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { 1,  0, -1,  0,  1, -1,  1, -1};
static const int dy[8] = { 0,  1,  0, -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

const int maxn = 300+5;

LL dp[maxn][maxn];
LL height[maxn];
int N,K;

void init(){
    _for(i,0,maxn) _for(j,0,maxn)  dp[i][j] = INF;
    dp[0][0] = 0;
    cin >> N >> K;
    _rep(i,1,N){
        cin >> height[i];
    }
    height[0] = 0;


}

int main()
{
    init();
    _rep(j,1,N-K){
        _rep(i,j,N){
            LL &ans = dp[i][j];
            _rep(k,j-1,i-1){
                ans = min(ans,dp[k][j-1] + max(height[i] - height[k],0LL));
            }
        }
    }

    /*
    _rep(i,0,N){
        _rep(j,0,N){
            printf("%lld ",dp[i][j]);
        }
        printf("\n");
    }
    */
    LL a = INF;
    _rep(i,N-K,N){
        a = min(dp[i][N-K],a);
    }

    cout << a <<endl;

    return 0;
}
