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

#define DEBUG_ //!!$BDs=P;~$K%3%a%s%H%"%&%H(B!!
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

const int mod = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


LL yhaa(LL x, LL n, LL mod){
    if (n == 0){
        return 1;
    }
    if (n%2 == 0){
        LL t = (yhaa(x,n/2, mod)) % mod;//偶数の時は半分
        return (t*t) % mod;
    }
    return (x * yhaa(x, n-1, mod)) % mod;
}

LL nCk(LL n,LL k,LL m){
    int K = k;
    LL X = 1;
    for(int i = 0; i < K;i++){
        X = (X*(n-i)) % m;
    }
    LL Y = 1;
    for(int i = 1; i < K+1; i++){
        Y = (Y*i) % m;
    }
    LL YY = yhaa(Y,1000000005,m);
    return (X*YY) % m;

}


int main(){
    int n, a, b;
    cin >> n >> a >> b;
    long long int m = 1000000007;
    if (n == 2){
        cout << 0 <<endl;
    }
    else{
        LL all = yhaa(2,n,m);
        LL C_a = nCk(n,a,m);
        LL C_b = nCk(n,b,m);
        if((all - C_a - C_b - 1 ) % m > 0){
            cout << (all - C_a - C_b - 1 ) % m << endl;
        }
        else{
            cout << m + (all - C_a - C_b - 1 ) % m << endl;
        }
    }
    
}
