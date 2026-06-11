// https://gcc.gnu.org/git/?p=gcc.git;a=blob;f=libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h
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
#include <array>
//#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rrep(i,n) for (int i=1; i<=(n); ++i)
#define drep(i,n) for (int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for (int i=s; i<t; ++i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1001001001;
const double PI = acos(-1);
const int mod=1e9+7;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd (ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm (ll a, ll b) { return a/gcd(a,b)*b; }
/*------------------------------------------------------------------------------
...................................ENTRY POINT..................................
------------------------------------------------------------------------------*/
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int d, t, s;
  cin >> d >> t >> s;
  if((double)d/s > t) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
