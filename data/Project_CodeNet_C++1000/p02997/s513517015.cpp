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


void solve(long long N, long long K){
    if(N == 2 && K == 0) {
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }

    LL max_k = (N - 1) * (N - 2) / 2;
    if(max_k < K) {
        cout << -1 << endl;
        return;
    }

    vector<PII> ans;
    REP(i, N-1) {
        ans.PB({1, i+2});
    }

    LL l = 2, r = 3;
    REP(i, max_k - K) {
        ans.PB({l, r});
        if(r == N) {
            l++;
            r = l + 1;
        } else {
            r++;
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    solve(N, K);
    return 0;
}
