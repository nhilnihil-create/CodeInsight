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
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
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

int leftcnt[2005][2005];
int rightcnt[2005][2005];
int upcnt[2005][2005];
int downcnt[2005][2005];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    char field[2005][2005];
    rep(i,0,h){
        rep(j,0,w) cin >> field[i][j];
    }

    rep(i,0,h){
        int cnt = 0;
        rep(j,0,w){
            if(field[i][j] == '.'){
                cnt++;
            }else{
                cnt = 0;
            }
            leftcnt[i][j] = cnt;
        }
    }

    rep(i,0,h){
        int cnt = 0;
        for(int j=w-1;j>=0;j--){
            if(field[i][j] == '.'){
                cnt++;
            }else{
                cnt = 0;
            }
            rightcnt[i][j] = cnt;
        }
    }

    rep(j,0,w){
        int cnt = 0;
        rep(i,0,h){
            if(field[i][j] == '.'){
                cnt++;
            }else{
                cnt = 0;
            }
            upcnt[i][j] = cnt;
        }
    }

    rep(j,0,w){
        int cnt = 0;
        for(int i=h-1;i>=0;i--){
            if(field[i][j] == '.'){
                cnt++;
            }else{
                cnt = 0;
            }
            downcnt[i][j] = cnt;
        }
    }

    int ans = 0;
    rep(i,0,h){
        rep(j,0,w){
            int tmp = leftcnt[i][j] + rightcnt[i][j] + upcnt[i][j] + downcnt[i][j] - 3;
            chmax(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
