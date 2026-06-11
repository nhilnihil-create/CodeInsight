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

bool solve(int N, string S, int ans) {
    if(ans == 0) return true;

    set<string> memo;
    queue<string> tmp;
    REP(j, ans) tmp.push("");
    REP(i, N) {
        memo.insert(tmp.front());
        tmp.pop();

        if(memo.count(S.substr(i, ans))) {
            return true;
        }
        tmp.push(S.substr(i, ans));
    }

    return false;
}

int main(){
    int N;
    string S;
    cin >> N >> S;
    int left = -1;
    int right = S.size() / 2 + 1;

    while(right - left > 1) {
        int mid = left + (right - left) / 2;
        if(solve(N, S, mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
