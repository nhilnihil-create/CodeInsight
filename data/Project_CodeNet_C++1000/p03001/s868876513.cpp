#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <cfenv>
#include <cinttypes>
#include <cstdint>
#endif
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
#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;

const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

ll gcd(ll x,ll y){
    x = x%y;
    return x == 0 ? y : gcd(y,x);
}
ll lcm(ll x, ll y){
    return x*y/gcd(x,y);
}



int main(){
 
    ll w,h,x,y;
    cin >> w >> h >> x >> y;
    double ans = w*h/2.0;
    cout << fixed << setprecision(10) << ans << " ";
    if(2 * x == w && 2 * y == h){
        cout << 1 << endl;        
    }else{
        cout << 0 << endl;
    }

    return 0;
}
