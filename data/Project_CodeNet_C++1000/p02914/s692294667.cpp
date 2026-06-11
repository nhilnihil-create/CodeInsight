#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int MAX_ROW = 63;
const int MAX_COL = 1e5+10;

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H,0);

    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = 0; row < A.H; ++row) {
            if(used[row]) continue;
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        for (int row = 0; row < A.H; ++row) {
            if (row != pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = true;
    }
}


signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    VL A(N);
    REP(i,N) cin >> A[i];
    const int MD = 60;

    LL res = 0;
    BitMatrix B(MD+1,N+1);
    vector<bool> cannot(MD+1,0);
    for(LL d = MD; d >= 0; d--){
        int num = 0;
        REP(i,N) if(A[i]&(1LL << d)) num++;

        if(num == 0){
            cannot[d] = 1;
            continue;
        }else if(num&1){
            cannot[d] = 1;
            res += (1LL << d);
            continue;
        }

        REP(i,N){
            if(A[i]&(1LL<<d)) B[MD-d][i] = 1;
        }
        B[MD-d][N] = 1;

    }

    GaussJordan(B,true);
    for(int d = MD; d >= 0; d--){
        if(cannot[d]) continue;

        bool ok = false;
        REP(i,N) if(B[MD-d][i]) ok = true;
        if(!B[MD-d][N]) ok = true;

        if(ok) res += (2LL << d);
    }
    cout << res << endl;

}
