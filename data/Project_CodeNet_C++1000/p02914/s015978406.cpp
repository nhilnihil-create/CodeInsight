//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N;
    cin >> N;
    ll A[N];
    REP(i,N) cin >> A[i];

    ll min_bit = 0;
    REP(i,N) min_bit ^= A[i];

    int interest[60];
    REP(i,60){
        if(1 & min_bit){
            interest[60-i-1] = 1;
        }
        else{
            interest[60-i-1] = 0;
        }
        min_bit >>= 1;
    }

    int bit_arr[N][60];
    REP(i,N)REP(j,60){
        if(A[i] & 1) bit_arr[i][60-j-1] = 1;
        else bit_arr[i][60-j-1] = 0;
        A[i] >>= 1;
    }

    int axis = 0;
    REP(i,60){
        if(interest[i] == 0){
            int ptr=axis;
            while(bit_arr[ptr][i] == 0 && ptr < N) ptr++;
            if(ptr >= N) continue;
            swap(bit_arr[axis], bit_arr[ptr]);
            FOR(j,0,N){
                if(j != axis){
                    if(bit_arr[j][i] == 1){
                        FOR(k, i, 60) if(interest[k]==0){bit_arr[j][k] ^= bit_arr[axis][k];}
                    }
                }
            }
            axis++;
        }
    }
    
    int ans_bit[60];
    REP(i,60) ans_bit[i] = 0;
    REP(i,N)REP(j,60) if(interest[j] == 0) ans_bit[j] ^= bit_arr[i][j];
    ll ans = 0;
    REP(i,60) if(ans_bit[60-i-1] == 1) ans += (ll)pow(2, i);
    ans *= 2;
    REP(i,60) if(interest[60-i-1] == 1) ans += (ll)pow(2,i);
    cout << ans << endl;

    return 0;
}