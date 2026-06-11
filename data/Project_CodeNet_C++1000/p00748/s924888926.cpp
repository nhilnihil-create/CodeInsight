#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EACH(t,i,c) for(t::iretator i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

int main() {
    vi four;
    int n = 1;
    while(true) {
        int num = n*(n+1)*(n+2)/6;
        if(num > 1000000) {
            break; 
        } else {
            four.push_back(num);
            n++;
        }
    }
    int fsize = four.size();

    vi dp(1000000+1, INF);
    vi dpk(1000000+1, INF);
    dp[0] = dpk[0] = 0;
 
    FOR(i, 1, 1000000) {
        REP(j, fsize) {
            if(i-four[j] >= 0) {
                dp[i] = min(dp[i-four[j]]+1, dp[i]);
                if(four[j]%2) {
                    dpk[i] = min(dpk[i-four[j]]+1, dpk[i]);
                }
            } else {
                break;
            }
        }
    }

    while(cin >> n, n) {
        cout << dp[n] << " " << dpk[n] << endl;
    }
 
    return 0;
}