#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

const LL MOD = 1000000007;

void solve(std::string S){
    int N = 13;
    int x = 1;
    VLL dp(13, 0LL);
    dp[0] = 1;

    RREP(i, S.size()-1) {
        VLL next_dp(13, 0LL);
        if(S[i] == '?') {
            REP(y, 10) {
                REP(j, N) {
                    (next_dp[(j + y * x) % N] += dp[j]) %= MOD;
                }
            }
        } else {
            int y = S[i] - '0';
            REP(j, N) {
                (next_dp[(j + y * x) % N] += dp[j]) %= MOD;
            }
        }

        REP(j, N) dp[j] = next_dp[j];

        x *= 10;
        x %= N;
    }

    cout << dp[5] << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

