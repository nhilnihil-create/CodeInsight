#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include <regex>
//#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int64_t f(int64_t n){
    return n*(n-1)/2;
}

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    vector<int64_t> a(n);
    rep(i,n)cin>>a[i], a[i]--;
    
    vector<int64_t> m(n,0);
    rep(i,n)m[a[i]]++;
    
    int64_t ans = 0;
    rep(i,n)ans += f(m[i]);
    
    for(int i=0; i<n; i++){
        cout << ans -f(m[a[i]]) + f(m[a[i]]-1) << endl;
        //printf("%lld\n", ans -f(m[a[i]]) + f(m[a[i]]-1));
    }
    
    return 0;
}