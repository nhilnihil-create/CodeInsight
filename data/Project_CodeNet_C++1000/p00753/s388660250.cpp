#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
bool prime[314514];
int rui[314514];

void init() {
    fill(prime, prime + 314514, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 314514; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < 314514; j += i) {
                prime[j] = false;
            }
        }
    }
    rep(i,0, 314514) {
        if (prime[i]) {
            rui[i]++;
        }
    }
    rep(i, 0, 314514 - 1) {
        rui[i + 1] += rui[i];
    }
//    rep(i,0,100){
//        if(prime[i]){
//            cout << i << " " << rui[i] << endl;
//        }
//    }
}

void solve(int n) {
    cout << rui[2 * n] - rui[n] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    while (true) {
        int n;
        cin >> n;
        if(n == 0) break;
        solve(n);
    }


    return 0;
}

