#include<bits/stdc++.h>
using namespace std;

using lnt = long long;
using Real = long double;

#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(lnt i=0;i<(n);++i)
#define RANGE(i, a, b) for(lnt i=(a);i<(b);++i)
#define RREP(i, n) for(lnt i=(n)-1;i>= 0;--i)

#define ln '\n'
#define pb push_back
#define eb emplace_back
#define pque priority_queue
#define umap unordered_map
#define uset unordered_set
#define dcout cout<<fixed<<setprecision(20)
#define summon_tourist cin.tie(0);ios::sync_with_stdio(false)

constexpr int dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,-1,0,1,1,-1,1,-1};
constexpr Real eps = 1e-9; const Real pi = acosl(-1);
constexpr lnt BIG = INT_MAX/10, BBIG = LLONG_MAX/10;

template<class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<class T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template<class T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template<class T> inline T nHr(T a,T b){return nCr(a+b-1,b);}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

using pint = pair<int, int>; using plnt = pair<lnt, lnt>;
using vint = vector<int>; using vlnt = vector<lnt>;
constexpr lnt MOD = 1e9+7;

lnt dp[2010][2010];

int main(){
    summon_tourist;

	lnt N, A[2000]; cin >> N;
    multimap<lnt, lnt, greater<lnt> > mp;
    REP(i, N) {
        cin >> A[i];
        mp.emplace(A[i], i);
    }
    REP(i, N+5) REP(j, N+5) dp[i][j] = -BBIG;
    dp[0][0] = 0;
    sort(A, A+N); reverse(A, A+N);
    auto itr = mp.begin();
    REP(i, N){
        lnt num = itr->first, idx = itr->second;
        // cerr << num << ' ' << idx << endl;
        REP(left, i+1){
            lnt right = i-left;
            chmax(dp[left+1][right], dp[left][right] + num*abs(idx-left));
            chmax(dp[left][right+1], dp[left][right] + num*abs(idx-(N-right-1)));
        }
        itr++;
    }
    lnt ans = 0;
    REP(i, N+1){
        chmax(ans, dp[i][N-i]);
    }
    cout << ans << ln;
}
