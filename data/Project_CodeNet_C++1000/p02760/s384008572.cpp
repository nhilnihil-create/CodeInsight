#include <bits/stdc++.h>
 
using namespace std;

// traduções

// even -> par
// odd -> impar

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-12
const double PI = acos(-1.0);

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define FILL(a,v) memset(a, v, sizeof a)

// bitmask operations
#define SETBIT(S, j) S |= (1 << j)
#define CLEARBIT(S, j) S &= ~(1 << j)
#define ISSET(S, j) S & (1 << j)
#define FLIPBIT(S, j) S ^= (1 << j)
#define LSBIT(S) (S & (-S))

// debug
#define DEBUGSTR(S) cout << "(" << S << ")\n";

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int A[3][3], N, bingo[3][3];

    REP(i, 0, 3)
        REP(j, 0, 3) {
            scanf(" %d", &A[i][j]);
            bingo[i][j] = 0;
        }

    scanf(" %d", &N);

    REP(i, 0, N) {
        int v;
        scanf(" %d", &v);

        REP(i, 0, 3)
            REP(j, 0, 3)
                if(A[i][j] == v)
                    bingo[i][j] = 1;
    }

    bool ok = false;

    if(bingo[0][0] && bingo[0][1] && bingo[0][2]) ok = true;
    if(bingo[1][0] && bingo[1][1] && bingo[1][2]) ok = true;
    if(bingo[2][0] && bingo[2][1] && bingo[2][2]) ok = true;

    if(bingo[0][0] && bingo[1][0] && bingo[2][0]) ok = true;
    if(bingo[0][1] && bingo[1][1] && bingo[2][1]) ok = true;
    if(bingo[0][2] && bingo[1][2] && bingo[2][2]) ok = true;

    if(bingo[0][0] && bingo[1][1] && bingo[2][2]) ok = true;
    if(bingo[0][2] && bingo[1][1] && bingo[2][0]) ok = true;    

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
