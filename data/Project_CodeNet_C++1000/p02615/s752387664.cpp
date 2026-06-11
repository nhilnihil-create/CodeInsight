/*input
*/

// #include<bits/stdc++.h>
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
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <tuple>
#endif
 
using namespace std;
long long mod=1e9+7;
long long INF=1e7;
double EPS = 1e-12;
const long long lim = 2e5+10;
typedef long long int lld;
typedef long long ll;

#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define mset(a, v) memset(a, v, sizeof(a))
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }


#define popcount __builtin_popcountll

ll powP(ll x, ll y) {
    ll ans = 1, po = x % mod;
    while(y > 0) {
        if(y & 1) ans = ans * po % mod;
        y >>= 1; po = po * po % mod;
    }
    return ans;
}


ll Array[lim],BArray[lim],dp[lim];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt 
    freopen("output.txt", "w", stdout);
    #endif

    lld T,i,p,j,l,e,r,b,c,k,q,a,d,w,x,y,u,v,z,t,curr,prev,sum=0,val,countA=0,indicator=0,pos,h,minA,maxA,type,n,m,ans=0,left,right;
    string A,B;
    cin>>n;
    rep(i,1,n) cin>>Array[i];
    sort(Array+1,Array+n+1);
    reverse(Array+1,Array+n+1); pos=1;
    // Error(Array[1]);
    rep(i,1,(n)/2) {
        if(i==1) ans+= Array[i];
        else ans += Array[i]*2;
    }
    if(n%2==1) ans+= Array[(n+1)/2];
    cout<<ans<<endl;
    return 0;
}



