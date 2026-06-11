#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll dp[100005][13];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string s; cin >> s;
    dp[0][0] = 1;
    rep(i,0,SZ(s)){
        rep(j,0,13){
            if(s[i] != '?'){
                int c = chartoint(s[i]);
                dp[i+1][(j*10+c)%13] = (dp[i+1][(j*10+c)%13] + dp[i][j]) % MOD;
            }else{
                rep(k,0,10){
                    dp[i+1][(j*10+k)%13] = (dp[i+1][(j*10+k)%13] + dp[i][j]) % MOD;
                }
            }
        }
    }

    cout << dp[SZ(s)][5] << endl;
    return 0;
}
