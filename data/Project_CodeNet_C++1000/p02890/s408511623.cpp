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

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    int N; cin >> N;
    map<int,int> mp;
    REP(i,N){
        int a; cin >> a;
        mp[a]++;
    }
    VI H;
    for(auto p : mp){
        H.eb(p.second);
    }
    int len = SZ(H);
    sort(H.begin(),H.end());
    VL aH(len+1);
    REP(i,len){
        aH[i+1] = aH[i] + H[i];
    }
    //for(auto i : aH){
    //    cout << i << " ";
    //}
    //cout << endl;

    FOR(i,1,N+1){
        LL ok = 0;
        LL ng = 1e6;
        while(abs(ok-ng) > 1){
            LL mid = (ok+ng) / 2;
            dump(mid)
            LL sum = 0;
            auto it = lower_bound(H.begin(),H.end(),mid);
            sum += mid * (H.end() - it);
            int index = it - H.begin();
            dump(sum)
            sum += aH[index];

            dump(sum)
            if(sum >= i*mid){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << ok << endl;
    }

}
