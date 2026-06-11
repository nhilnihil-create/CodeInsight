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

bool check(int N){
    while(N != 1){
        if(N%2 == 0){
            N /= 2;
        }
        else{
            break;
        }
    }
    if(N != 1) return true;
    else return false;

}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    bool ok = check(N);
    if(!ok){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    if(N%2 != 0){
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << 1 << " " << 3+N << endl;
        cout << 3+N << " " << 2+N << endl;
        cout << 2+N << " " << 1+N << endl;

        FOR(i,4,N+1){
            if(i%2 == 0){
                cout << i << " " << 1 << endl;
                cout << i << " " << (i+1)+N << endl;
                cout << i+1 << " " << 1 << endl;
                cout << i+1 << " " << i+N << endl;
            }
        }
    }
    else{
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << 1 << " " << 3+N << endl;
        cout << 3+N << " " << 2+N << endl;
        cout << 2+N << " " << 1+N << endl;

        FOR(i,4,N){
            if(i%2 == 0){
                cout << i << " " << 1 << endl;
                cout << i << " " << (i+1)+N << endl;
                cout << i+1 << " " << 1 << endl;
                cout << i+1 << " " << i+N << endl;
            }
        }

        int base = 1;
        while(base*2 < N){
            base *= 2;
        }
        int rem = N - base + 1;
        if(rem == 3) rem = 3 + N;
        cout << base << " " << N << endl;
        cout << rem << " " << 2*N << endl;
    }


}
