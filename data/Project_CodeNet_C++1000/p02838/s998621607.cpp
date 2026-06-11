// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <array>
#include <atomic>
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
#endif
//#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
typedef long long ll;
#define rep(i, z, n) for(ll i = z; i < n; i++)
//const int INF = 1<<29;
const ll MOD = 1000000007;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A.at(i);
    ll ans = 0;
    rep(j, 0, 60){
        ll count_1 = 0;
        rep(i, 0, N){
            if((A.at(i)>>j)&1){
                count_1++;
                //cout << "i " << i << " A.at(i) " << A.at(i) << " j " << j << endl;
            }
        }
        ll count_0 = N - count_1;
        ll pro = (count_0 * count_1) % MOD;
        rep(k, 0, j){
            pro *= 2;
            pro %= MOD;
        }
        ans += pro;
        ans %= MOD;
        //cout << count_0 << " " << count_1 << " " << ans << endl;
    }
    cout << ans << endl;
}
